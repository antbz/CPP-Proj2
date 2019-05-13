cmake_minimum_required(VERSION 3.13)
project(Proj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proj2
        Proj2/Source.cpp Proj2/utilities.cpp Proj2/Address.cpp Proj2/Date.cpp
        Proj2/Client.cpp Proj2/Packet.cpp Proj2/scratch.cpp)
