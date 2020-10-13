cmake_minimum_required(VERSION 3.17)
project(P2PMultiplayer)

set(CMAKE_CXX_STANDARD 20)

add_library(P2PMultiplayer SHARED library.cpp library.h peer.cpp peer.h keyexchange.cpp keyexchange.h)