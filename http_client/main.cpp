//
// Copyright (c) 2016-2017 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

//------------------------------------------------------------------------------
//
// Example: HTTP client, asynchronous
//
//------------------------------------------------------------------------------

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <tao/json.hpp>

using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
namespace http = boost::beast::http;    // from <boost/beast/http.hpp>

//------------------------------------------------------------------------------

// Report a failure
void
fail(boost::system::error_code ec, char const* what)
{
    std::cerr << what << ": " << ec.message() << "\n";
}

// Performs an HTTP GET and prints the response
class session : public std::enable_shared_from_this<session>
{
    tcp::resolver resolver_;
    tcp::socket socket_;
    boost::beast::flat_buffer buffer_; // (Must persist between reads)
    http::request<http::string_body> req_;
    http::response<http::string_body> res_;

public:
    // Resolver and socket require an io_context
    explicit
    session(boost::asio::io_context& ioc)
            : resolver_(ioc)
            , socket_(ioc)
    {
    }

    // Start the asynchronous operation
    void
    run(
        int number,
            char const* host,
            char const* port,
            char const* target,
            int version)
    {
        // Set up an HTTP GET request message
        req_.version(version);
        req_.method(http::verb::post);
        req_.target(target);
      tao::json::value json_object = {
          {"string", std::string(1024, '0')},
          {"number", number}
      };

        req_.body() = tao::json::to_string(json_object);
        req_.set(http::field::content_type, "application/json");
      req_.set(boost::beast::http::field::content_length, req_.body().size());
        req_.set(http::field::host, host);
        req_.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

        // Look up the domain name
        resolver_.async_resolve(
                host,
                port,
                std::bind(
                        &session::on_resolve,
                        shared_from_this(),
                        std::placeholders::_1,
                        std::placeholders::_2));
    }

    void
    on_resolve(
            boost::system::error_code ec,
            tcp::resolver::results_type results)
    {
        if(ec)
            return fail(ec, "resolve");

        // Make the connection on the IP address we get from a lookup
        boost::asio::async_connect(
                socket_,
                results.begin(),
                results.end(),
                std::bind(
                        &session::on_connect,
                        shared_from_this(),
                        std::placeholders::_1));
    }

    void
    on_connect(boost::system::error_code ec)
    {
        if(ec)
            return fail(ec, "connect");

        // Send the HTTP request to the remote host
        http::async_write(socket_, req_,
                          std::bind(
                                  &session::on_write,
                                  shared_from_this(),
                                  std::placeholders::_1,
                                  std::placeholders::_2));
    }

    void
    on_write(
            boost::system::error_code ec,
            std::size_t bytes_transferred)
    {
        boost::ignore_unused(bytes_transferred);

        if(ec)
            return fail(ec, "write");

        // Receive the HTTP response
        http::async_read(socket_, buffer_, res_,
                         std::bind(
                                 &session::on_read,
                                 shared_from_this(),
                                 std::placeholders::_1,
                                 std::placeholders::_2));
    }

    void
    on_read(
            boost::system::error_code ec,
            std::size_t bytes_transferred)
    {
        boost::ignore_unused(bytes_transferred);

        if(ec)
            return fail(ec, "read");

        // Write the message to standard out
        std::cout << res_ << std::endl;

        // Gracefully close the socket
        socket_.shutdown(tcp::socket::shutdown_both, ec);

        // not_connected happens sometimes so don't bother reporting it.
        if(ec && ec != boost::system::errc::not_connected)
            return fail(ec, "shutdown");

        // If we get here then the connection is closed gracefully
    }
};

//------------------------------------------------------------------------------

int main(int argc, char** argv)
{
    auto const host = "127.0.0.1";
    auto const port = "8081";
  // "/count" just convert
  // "/do_something" go thru grpc
    auto const target = "/count";
    int version = 10;

    // The io_context is required for all I/O
    boost::asio::io_context ioc;

    // Launch the asynchronous operation
    std::vector<std::shared_ptr<session>> sessions;
    for (int i = 0; i < 1000; ++i) {
      sessions.push_back(std::make_shared<session>(ioc));
      sessions.back()->run(i, host, port, target, version);
    }


    // Run the I/O service. The call will return when
    // the get operation is complete.
    ioc.run();

    return EXIT_SUCCESS;
}