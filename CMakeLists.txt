cmake_minimum_required(VERSION 3.17)
project(P2PMultiplayer)

set(CMAKE_CXX_STANDARD 20)

add_library(P2PMultiplayer SHARED library.cpp library.h
        Blockchain/Block.cpp Blockchain/Block.h Blockchain/Blockchain.cpp Blockchain/Blockchain.h
        crypto/sha256.cpp crypto/sha256.h
        net/Protocol.h
        net/Socket.h
)
if(WIN32)
    target_link_libraries(P2PMultiplayer wsock32 ws2_32)
endif()