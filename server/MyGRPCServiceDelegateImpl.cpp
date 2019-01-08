//
// Created by naum on 07/01/2019.
//

#include "MyGRPCServiceDelegateImpl.h"

std::string MyGRPCServiceDelegateImpl::do_something(const std::string& action) {
    return action + " done!";
}