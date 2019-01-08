//
// Created by naum on 07/01/2019.
//

#ifndef PROJECT_MYGRPCSERVICEDELEGATEIMPL_H
#define PROJECT_MYGRPCSERVICEDELEGATEIMPL_H

#include "grpc_service/MyGRPCServiceDelegate.h"

class MyGRPCServiceDelegateImpl : public MyGRPCServiceDelegate {
public:
    std::string do_something(const std::string& action) override;
};


#endif //PROJECT_MYGRPCSERVICEDELEGATEIMPL_H
