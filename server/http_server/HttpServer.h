//
// Created by naum on 06/01/2019.
//

#ifndef PROJECT_HTTP_SERVER_H
#define PROJECT_HTTP_SERVER_H

#include "HttpServerDelegate.h"

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>

class HttpServer final {
public:
    HttpServer(boost::asio::ip::address address, unsigned short port, std::unique_ptr<HttpServerDelegate> delegate, boost::asio::io_context& ioc);

private:
    void handle_request();

    boost::asio::io_context& ioc_;
    boost::asio::ip::tcp::acceptor acceptor_;
    boost::asio::ip::tcp::socket socket_;
    std::unique_ptr<HttpServerDelegate> delegate_;
};
#endif //PROJECT_HTTP_SERVER_H
