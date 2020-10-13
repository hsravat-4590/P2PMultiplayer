//
// Created by Hanzalah Ravat on 12/10/2020.
//
#include "peer.h"
#include <xstring>

class Peer{

private:
    int port = 10000; // The Default port for a peer.
    std::string host = nullptr; // The ip/domain of the peer
    std::string pk = nullptr; // The Private key to connect to this peer. Will be generated using pseudo-random key and a diffie helman key exchange

public:
    const bool encryptTraffic = true; // True by default use-case scenarios. Only turn this flag off in debug scenarios
    // Constructs a Peer type using a hostname and connects to the default port
    Peer(std::string host){
        this->host = host;
    }
    // Constructs a Peer type using both hostname and port
    Peer(int port, std::string host){
        this->port = port;
        this->host = host;
    }


};