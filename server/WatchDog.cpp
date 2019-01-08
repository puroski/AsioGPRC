//
// Created by naum on 07/01/2019.
//

#include "WatchDog.h"

WatchDog::WatchDog(boost::asio::io_context& observable, boost::asio::io_context& ioc)
        : observable_{observable}
        , deadline_timer_{ioc} {
    reset_timer();
}

void WatchDog::check_observable() {
    observable_.post([&]{
        reset_timer();
    });
}

void WatchDog::reset_timer() {
    deadline_timer_.expires_from_now(boost::posix_time::seconds(5));
    deadline_timer_.async_wait(std::bind(&WatchDog::handle_timeout, this, std::placeholders::_1));
    check_observable();
}

void WatchDog::handle_timeout(const boost::system::error_code& error_code) {
    if (!error_code) {
        exit(EXIT_FAILURE);
    }
}