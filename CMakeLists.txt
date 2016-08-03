cmake_minimum_required(VERSION 3.3)
project(MatriciesHoffmanProjectV0_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Menu/Menu.c Menu/Menu.h MainProgram/Main.c MainProgram/Main.h
        "SystemMethods/GetDimenByHand.c" "SystemMethods/GetDimenByHand.h"
        "SystemMethods/GetMatrixByHand.c" "SystemMethods/GetMatrixByHand.h"
        "SystemMethods/IOFileMethods.c" "SystemMethods/IOFileMethods.h"
    )
add_executable(MatriciesHoffmanProjectV0_1 ${SOURCE_FILES})