//
// Created by naum on 07/01/2019.
//

#ifndef PROJECT_HTTPSERVERDELEGATE_H
#define PROJECT_HTTPSERVERDELEGATE_H

#include <cstddef>
#include <ctime>
#include <string>
#include <functional>

class HttpServerDelegate {
public:
    virtual ~HttpServerDelegate() = default;

    virtual std::size_t request_count() = 0;
    virtual std::time_t now() = 0;

    virtual void do_something(const std::string& action, std::function<void(const std::string&)> callback) = 0;
};

#endif //PROJECT_HTTPSERVERDELEGATE_H
