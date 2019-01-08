//
// Created by naum on 07/01/2019.
//

#ifndef PROJECT_MYGRPCSERVICEDELEGATE_H
#define PROJECT_MYGRPCSERVICEDELEGATE_H

#include <string>

class MyGRPCServiceDelegate {
public:
    virtual ~MyGRPCServiceDelegate() = default;

    virtual std::string do_something(const std::string& action) = 0;
};

#endif //PROJECT_MYGRPCSERVICEDELEGATE_H
