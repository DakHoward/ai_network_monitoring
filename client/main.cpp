#include<boost/asio.hpp>
#include<iostream>
#include "client.h"
int main()
{
    const std::string name = "localhost";
    const std::string port = "8040";
    client myclient(name, port);
    myclient.run();
    const std::string message = "hello from client";
    myclient.send(message);
    
}
