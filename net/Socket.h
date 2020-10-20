////
// Created by Hanzalah Ravat on 20/10/2020.
//
//
#ifndef P2PMULTIPLAYER_SOCKETCOMMON_H
#define P2PMULTIPLAYER_SOCKETCOMMON_H
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
#include "Protocol.h"
#endif //P2PMULTIPLAYER_SOCKETCOMMON_H
