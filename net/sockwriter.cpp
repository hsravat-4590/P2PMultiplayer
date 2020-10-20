////
// Created by Hanzalah Ravat on 17/10/2020.
//
//
#include "sockwriter.h"

std::string mTarget = nullptr;
int mPort = 0;
Protocols mProtocol;
const char *TargetHost;
int sd;
struct sockaddr_in server;
struct in_addr ipv4addr;
struct hostent *hp;

SockWriter::SockWriter(const char *target, int port, Protocols protocol) {
    mTarget = target;
    mPort = port;
    mProtocol = protocol;
    TargetHost = target;
    if(mProtocol == Protocols::TCP) //TCP
        sd = socket(AF_INET, SOCK_STREAM, 0);
    if(mProtocol == Protocols::UDP) //UDP
        sd = socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family = AF_INET;
    inet_pton(AF_INET,TargetHost,&ipv4addr);
    hp = gethostbyaddr(reinterpret_cast<const char *>(&ipv4addr), sizeof ipv4addr, AF_INET);

    memcpy(hp->h_addr, &(server.sin_addr.s_addr), hp->h_length);
    server.sin_port = htons(mPort);
    connect(sd, (const sockaddr *)&server, sizeof(server));
}
std::string SockWriter::SetFormat(std::string message) {
    return message; //WIP: This function hasn't been completed as a format hasnt been created yet
}

void SockWriter::BytesSend(unsigned char *messages) {
    ::send(sd, reinterpret_cast<const char *>(messages), strlen(reinterpret_cast<const char *>(messages)), 0);
}
void SockWriter::MessageSend(std::string message) {
    message = SetFormat(message);
    ::send(sd, (char *)message.c_str(), strlen((char *)message.c_str()), 0);
}
