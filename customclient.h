#ifndef CUSTOMCLIENT_H
#define CUSTOMCLIENT_H

#include <tcpclient.h>
#include <thread>
#include <time.h>
#include <sys/time.h>
#include <math.h>

class CustomClient : public TCPClient
{
    using TCPClient::TCPClient;

public:
    void SetDelay(uint timems);
    void MessageBroker(std::string message_template);

private:
    uint message_delay;
};

#endif // CUSTOMCLIENT_H
