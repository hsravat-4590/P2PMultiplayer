cmake_minimum_required(VERSION 3.17)
project(P2PMultiplayer)

set(CMAKE_CXX_STANDARD 20)

set(lib_SOURCES library.cpp library.h
        Blockchain/Block.cpp Blockchain/Block.h Blockchain/Blockchain.cpp Blockchain/Blockchain.h
        crypto/sha256.cpp crypto/sha256.h
        ext/TinyThread++-1.1/fast_mutex.h ext/TinyThread++-1.1/tinythread.cpp ext/TinyThread++-1.1/tinythread.h
        net/Protocol.h
        net/Socket.h
        )
if(WIN32)
# Include sources which should only be included in Windows
endif()
if(POSIX)
# Include sources which should only be included in POSIX-type Operating Systems
endif()

add_library(P2PMultiplayer SHARED ${lib_SOURCES})

if(WIN32)
    target_link_libraries(P2PMultiplayer wsock32 ws2_32)
endif()
