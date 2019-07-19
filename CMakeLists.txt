cmake_minimum_required(VERSION 3.14)
project(Highprecision)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_SRCS)

list(APPEND DIR_SRCS
        ./include/DataStructs.h
        ./include/Add.h
        ./include/Sub.h
        ./include/Mul.h

        ./src/Add.cpp
        ./src/Sub.cpp
        ./src/Mul.cpp)

add_executable(Highprecision main.cpp ${DIR_SRCS} include/DataStructs.h include/Add.h src/Add.cpp include/Sub.h src/Sub.cpp include/Mul.h src/Mul.cpp include/GetElem.h)