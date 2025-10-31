#ifndef CLIENT_H
#define CLIENT_H
#include<boost/asio.hpp>
#include<iostream>
#include<string>

class client
{    
    private:
        boost::asio::io_context io_;
        boost::asio::ip::tcp::socket socket_{io_};
    public:
        
        client(const std::string& host, const std::string& port)
        {
            boost::asio::ip::tcp::resolver resolver(io_);
            auto endpoints = resolver.resolve(host, port);
            boost::asio::connect(socket_, endpoints);
            std::cout << "Connected to server \n"; 
        }
        void send(const std::string& message)
        {
            boost::asio::write(socket_, boost::asio::buffer(message));
        }
        void run()
        {
            io_.run();
        }
};
#endif
