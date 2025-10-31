#include<boost/asio.hpp>
#include<iostream>

int main()
{
    //set io_context to use sockets for synchronous networking
    boost::asio::io_context io;
    boost::asio::ip::tcp::socket socket(io);
    
    //connect to local host on port 8040, send data
    boost::asio::ip::tcp::resolver resolver(io);
    auto endpoints = resolver.resolve("localhost", "8040");
    boost::asio::connect(socket, endpoints);
    boost::asio::write(socket, boost::asio::buffer("hello server from client"));

    //shutdown socket and clean up resources
    socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
    socket.close();
}
