////
// Created by Hanzalah Ravat on 20/10/2020.
//
//
#ifndef P2PMULTIPLAYER_SOCKET_H
#define P2PMULTIPLAYER_SOCKET_H
//Network related includes:
#ifdef _WIN32
#include <winsock2.h>
#include <WS2tcpip.h>
#include <ws2def.h>
#elif __linux__
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#endif //WIN64 or Linux checks for the compiler
// Protocols
#include "Protocol.h"
//Other headers
#include <string>
#include <thread>
//Constants
#define MAX 80
#define SA struct sockaddr
#endif //P2PMULTIPLAYER_SOCKET_H
//Class to maintain a socket connection between two nodes on the network

class Socket{
public:
    Socket(struct sockaddr_in servaddr, const int port, Protocols protocol){
        PORT = port;
        // Create a Socket and verify
        switch(protocol){
            case TCP: sockfd = socket(AF_INET, SOCK_STREAM, 0); break;
            case UDP: sockfd = socket(AF_INET, SOCK_DGRAM, 0); break;
        }
        if(sockfd !=-1){
            memset(&servaddr,0, sizeof(servaddr));
            // assign IP, PORT
            servaddr.sin_family = AF_INET;
            servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
            servaddr.sin_port = htons(PORT);
            if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
                printf("socket bind failed...\n");
                binded = false;
            }
            else {
                printf("Socket successfully binded..\n");
                binded = true;
            }
            this->servaddr = servaddr;
        }

    }
    void BytesSend(unsigned char *messages) {
        ::send(sockfd, reinterpret_cast<const char *>(messages), strlen(reinterpret_cast<const char *>(messages)), 0);
    }
    void MessageSend(std::string message) {
        message = SetFormat(message);
        ::send(sockfd, (char *)message.c_str(), strlen((char *)message.c_str()), 0);
    }
protected:
    virtual void OnBytesRecv(char bytes[]) = 0;
    virtual void OnMessageRecieved(std::string textMsg) = 0;
    virtual void SetFormat(std::string message) = 0;
private:
    bool threadRunning,binded;
    int PORT, sockfd,connfd,len;
    struct sockaddr_in servaddr, cli;
    char buffer[MAX];
    std::thread ListenerThread;
    void StartListener(){
        threadRunning = true;
        ListenerThread(ListenerTask);
        ListenerThread.join();
        printf("ListenerThread has exited \n");
    };
    void StopListener(){threadRunning = false;}

    void ListenerTask(){
        while(threadRunning) {
            memset(buffer,0, MAX);
            // read the message from client and copy it in buffer
            ::read(sockfd, buffer, sizeof(buffer));
            OnBytesRecv(buffer);
            memset(buffer,0,MAX);
        }
    }

};
