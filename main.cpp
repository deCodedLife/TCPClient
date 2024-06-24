#include <iostream>
#include "tcp/tcpserver.h"
#include "tcp/tcpclient.h"

#define SERVER_HOST "127.0.0.1"
#define SERVER_PORT 5011

using namespace std;

int main(int argc, char **argv)
{
    // uint server_port = SERVER_PORT;

    // if (argc == 1) {
    //     std::cout << "[-] Warn! Port not specified. Default: "
    //               << SERVER_PORT << " Will be used" << std::endl;
    // }
    // else server_port = (uint) std::atoi(argv[1]);

    // TCPUser server_data = TCPUser(0, NetAddr {
    //     .tcp_host = SERVER_HOST,
    //     .tcp_port = server_port
    // });

    // TCPServer server(server_data);
    // server.ListenAll();

    //**
    uint server_port = SERVER_PORT;

    if (argc == 1) {
        std::cout << "[-] Warn! Port not specified. Default: "
                  << SERVER_PORT << " Will be used" << std::endl;
    }
    else server_port = (uint) std::atoi(argv[1]);

    TCPUser server_data = TCPUser(0, NetAddr {
        .tcp_host = "127.0.0.1",
        .tcp_port = server_port
    });

    TCPClient client;
    client.ConnectTo(server_data);
    client.NewNessage("Here we goooooooooo!");

    return 0;
}
