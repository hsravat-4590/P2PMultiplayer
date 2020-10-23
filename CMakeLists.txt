cmake_minimum_required(VERSION 3.17)
project(P2PMultiplayer)

set(CMAKE_CXX_STANDARD 20)

set(lib_SOURCES library.cpp library.h
        Blockchain/Block.cpp Blockchain/Block.h Blockchain/Blockchain.cpp Blockchain/Blockchain.h
        crypto/sha256.cpp crypto/sha256.h
        ext/TinyThread++-1.1/fast_mutex.h ext/TinyThread++-1.1/tinythread.cpp ext/TinyThread++-1.1/tinythread.h
        net/Protocol.h
        net/Socket.h
        platform/common/Runnable.h)
if(WIN32)
    set(lib_SOURCES ${lib_SOURCES}
            platform/win32/WinThread.cpp platform/win32/WinThread.h)
endif()
if(POSIX)
    set(lib_SOURCES ${lib_SOURCES}
            platform/common/Thread.h platform/posix/PosixThread.cpp platform/posix/PosixThread.h platform/win32/WinThread.cpp platform/win32/WinThread.h)
endif()

add_library(P2PMultiplayer SHARED ${lib_SOURCES})

if(WIN32)
    target_link_libraries(P2PMultiplayer wsock32 ws2_32)
endif()
