////
// Created by Hanzalah Ravat on 17/10/2020.
//
//
#ifndef P2PMULTIPLAYER_SOCKWRITER_H
#define P2PMULTIPLAYER_SOCKWRITER_H
//General includes:
#include <iostream>
#include <stdio.h>
#include <string>

#include "SocketCommon.h"

class SockWriter {
public:
    SockWriter(const char *target, int port, Protocols protocol);
    // Send a String message to target(s)
    void MessageSend(std::string message);

    // Send a Message of Bytes rather than plaintext. Better for application usages
    void BytesSend(unsigned char messages[]);

private:
    void send(unsigned char bytes[]);

    std::string SetFormat(std::string message); // Adds a format to the string

    std::string message; // Message to send

};


#endif //P2PMULTIPLAYER_SOCKWRITER_H
