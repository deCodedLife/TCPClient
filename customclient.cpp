#include "customclient.h"

void CustomClient::SetDelay(uint timems)
{
    message_delay = timems;
}

void CustomClient::MessageBroker(std::string message_template)
{
    if (message_delay == 0) message_delay = 1000;
    std::chrono::duration delay = std::chrono::milliseconds(message_delay);

    while(true)
    {
        std::this_thread::sleep_for(delay);
        std::string userMessage = "";
        time_t current_time = time(NULL);

        char buff[256];
        strftime(buff, sizeof(buff), "[%Y-%m-%d %H:%M:%S", localtime(&current_time));

        timeval time;
        gettimeofday(&time, NULL);

        int millisec = lrint(time.tv_usec/1000.0);
        if (millisec >= 1000) {
            millisec -= 1000;
            time.tv_sec++;
        }

        snprintf(buff, sizeof(buff), "%s.%03d] %s", buff, millisec, message_template.c_str());
        userMessage = buff;

        NewNessage(userMessage);
    }
}
