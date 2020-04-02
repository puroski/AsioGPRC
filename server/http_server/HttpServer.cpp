//
// Copyright (c) 2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

//------------------------------------------------------------------------------
//
// Example: HTTP server, small
//
//------------------------------------------------------------------------------

#include "HttpServer.h"

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>
#include <tao/json/value.hpp>
#include <tao/json.hpp>

namespace ip = boost::asio::ip;         // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio.hpp>
namespace http = boost::beast::http;    // from <boost/beast/http.hpp>

class HttpConnection : public std::enable_shared_from_this<HttpConnection>
{
public:
    HttpConnection(tcp::socket socket, HttpServerDelegate& delegate, boost::asio::io_context& ioc)
            : socket_(std::move(socket))
            , delegate_{delegate}
            , ioc_{ioc}
            , deadline_{ioc, std::chrono::seconds(60)}{}

    // Initiate the asynchronous operations associated with the connection.
    void start() {
        read_request();
        check_deadline();
    }

private:
    // The socket for the currently connected client.
    tcp::socket socket_;
    HttpServerDelegate& delegate_;
    boost::asio::io_context& ioc_;

    // The buffer for performing reads.
    boost::beast::flat_buffer buffer_{8192};

    // The request message.
    http::request<http::string_body> request_;

    // The response message.
    http::response<http::dynamic_body> response_;

    // The timer for putting a deadline on connection processing.
    boost::asio::basic_waitable_timer<std::chrono::steady_clock> deadline_;

    // Asynchronously receive a complete request message.
    void read_request() {
        auto self = shared_from_this();

        http::async_read(
                socket_,
                buffer_,
                request_,
                [self](boost::beast::error_code ec,
                       std::size_t bytes_transferred) {
                    boost::ignore_unused(bytes_transferred);
                    if(!ec)
                        self->process_request();
                });
    }

    // Determine what needs to be done with the request message.
    void process_request() {
        response_.version(request_.version());
        response_.keep_alive(false);

        switch(request_.method()) {
            case http::verb::post:
                response_.result(http::status::ok);
                response_.set(http::field::server, "Beast");
                process_response();
                break;

            default:
                // We return responses indicating an error if
                // we do not recognize the request method.
                response_.result(http::status::bad_request);
                response_.set(http::field::content_type, "text/plain");
                boost::beast::ostream(response_.body())
                        << "Invalid request-method '"
                        << request_.method_string().to_string()
                        << "'";
                break;
        }
    }

    // Construct a response message based on the program state.
    void process_response()
    {
        auto temp = request_.target();
        if(request_.target() == "/count")
        {
          auto json = tao::json::from_string(request_.body());
            response_.set(http::field::content_type, "text/html");
            boost::beast::ostream(response_.body())
                    << "<html>\n"
                    <<  "<head><title>Request count</title></head>\n"
                    <<  "<body>\n"
                    <<  "<h1>Request count</h1>\n"
                    <<  "<p>There have been "
                    <<  delegate_.request_count()
                    <<  " requests so far.</p>\n"
                    <<  "</body>\n"
                    <<  "</html>\n";
            write_response();
        }
        else if(request_.target() == "/time")
        {
            response_.set(http::field::content_type, "text/html");
            boost::beast::ostream(response_.body())
                    <<  "<html>\n"
                    <<  "<head><title>Current time</title></head>\n"
                    <<  "<body>\n"
                    <<  "<h1>Current time</h1>\n"
                    <<  "<p>The current time is "
                    <<  delegate_.now()
                    <<  " seconds since the epoch.</p>\n"
                    <<  "</body>\n"
                    <<  "</html>\n";
            write_response();
        }
        else if(request_.target() == "/do_something")
        {
            delegate_.do_something(request_.body(), [&](const std::string& result) {
                response_.set(http::field::content_type, "text/html");
                boost::beast::ostream(response_.body())
                        <<  "<html>\n"
                        <<  "<head><title>Do something</title></head>\n"
                        <<  "<body>\n"
                        <<  "<h1>GRPC call test</h1>\n"
                        <<  "<p>The result of that call is: "
                        <<  result
                        <<  "</p>\n"
                        <<  "</body>\n"
                        <<  "</html>\n";
                write_response();
            });
        }
        else if(request_.target() == "/hang")
        {
            ioc_.post([]{
                std::this_thread::sleep_for(std::chrono::minutes(1));
            });
        }
        else
        {
            response_.result(http::status::not_found);
            response_.set(http::field::content_type, "text/plain");
            boost::beast::ostream(response_.body()) << "File not found\r\n";
            write_response();
        }
    }

    // Asynchronously transmit the response message.
    void write_response() {
        auto self = shared_from_this();

        response_.set(http::field::content_length, response_.body().size());

        http::async_write(
                socket_,
                response_,
                [self](boost::beast::error_code ec, std::size_t) {
                    self->socket_.shutdown(tcp::socket::shutdown_send, ec);
                    self->deadline_.cancel();
                });
    }

    // Check whether we have spent enough time on this connection.
    void check_deadline() {
        auto self = shared_from_this();

        deadline_.async_wait(
                [self](boost::beast::error_code ec) {
                    if(!ec) {
                        // Close socket to cancel any outstanding operation.
                        self->socket_.close(ec);
                    }
                });
    }
};

HttpServer::HttpServer(boost::asio::ip::address address, unsigned short port, std::unique_ptr<HttpServerDelegate> delegate, boost::asio::io_context& ioc)
    : ioc_{ioc}
    ,acceptor_{ioc, {address, port}}
    , socket_{ioc}
    , delegate_{std::move(delegate)} {
    handle_request();
}

void HttpServer::handle_request() {
    acceptor_.async_accept(socket_, [&](boost::beast::error_code ec) {
        if(!ec) {
            std::make_shared<HttpConnection>(std::move(socket_), *delegate_, ioc_)->start();
        }
        handle_request();
    });
}
