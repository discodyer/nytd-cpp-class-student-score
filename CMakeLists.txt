cmake_minimum_required(VERSION 3.0.0)

SET(PROJECT_NAME Score-Management-System)
project(${PROJECT_NAME})
#include(CTest)
#enable_testing()
message(STATUS "#####################################")

MESSAGE(STATUS "Building OS : ${CMAKE_SYSTEM}")

include_directories(./include)

aux_source_directory(src DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})

message(STATUS "Project Name: ${PROJECT_NAME}")
message(STATUS "Source dir  : ${CMAKE_SOURCE_DIR}")
message(STATUS "CXX Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "CXX FLAGS   : ${CMAKE_CXX_FLAGS}")

set( CMAKE_BUILD_TYPE "Debug" )
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


message(STATUS "#####################################")
