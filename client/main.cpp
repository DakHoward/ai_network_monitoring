#include<boost/asio.hpp>
#include<iostream>
#include "client.h"
int main()
{
    const std::string name = "localhost";
    const std::string port = "8040";
    client myclient(name, port);
    myclient.run();
    
    for(int i = 0; i < 5; i++)
    {
        std::string message;
        std::getline(std::cin, message);
        myclient.send(message + "\n");
    }
}
