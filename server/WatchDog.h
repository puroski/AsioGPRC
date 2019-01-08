//
// Created by naum on 07/01/2019.
//

#ifndef PROJECT_WATCHDOG_H
#define PROJECT_WATCHDOG_H

#include <boost/asio/deadline_timer.hpp>

class WatchDog {
public:
    WatchDog(boost::asio::io_context& observable, boost::asio::io_context& ioc);

private:
    void check_observable();
    void reset_timer();
    void handle_timeout(const boost::system::error_code& error_code);

    boost::asio::deadline_timer deadline_timer_;
    boost::asio::io_context& observable_;
};


#endif //PROJECT_WATCHDOG_H
