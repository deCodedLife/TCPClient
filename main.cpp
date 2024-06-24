#include <iostream>
#include "customclient.h"

#define SERVER_HOST "127.0.0.1"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "[!] Err! Server port and duration should be specified."
                  << std::endl << "Exemple: "
                  << "app [name] [port] [duration(seconds)]"
                  << std::endl
                  << "client TEST 3000 2" << std::endl;
        exit(-1);
    }
    std::string client_name = argv[1];
    uint server_port = (uint) std::atoi(argv[2]);
    uint message_delay = (uint) std::atoi(argv[3]);

    TCPUser server_data = TCPUser(0, NetAddr {
        .tcp_host = SERVER_HOST,
        .tcp_port = server_port
    });

    CustomClient client;
    client.ConnectTo(server_data);
    client.SetDelay(message_delay * 1000);

    std::thread messageHandler([&](){
        client.MessageBroker(client_name);
    });

    messageHandler.join();
    return 0;
}
