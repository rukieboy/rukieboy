cmake_minimum_required(VERSION 2.8)

PROJECT(HashTest1)
set(CMAKE_CXX_FLAGS xx)
set(TOP_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_DIR ${TOP_DIR}/src)
#set(THIRD_PARTY_DIR ${TOP_DIR}/third_party)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lpthread -ldl")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -ldl")

set(CMAKE_EXE_LINKER_FLAGS "-lpthread -ldl")
set(CMAKE_SHARED_LINKER_FLAGS "-lpthread -ldl")
set(CMAKE_MODULE_LINKER_FLAGS "-lpthread -ldl")

#set(GTEST_INCLUDE_DIRS 
#	${THIRD_PARTY_DIR}/gtest/googlemock/include
#	${THIRD_PARTY_DIR}/gmock/include
#)

include_directories(${TOP_DIR}/include)
#link_directories(/usr/lib ${TOP_DIR}/lib)
#add_definitions(-std=c++11)

set(LIBRARY_OUTPUT_PATH ${TOP_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${TOP_DIR}/bin)

message("***********************************************")
message("* Global CMake Settings")
message("*==============================================")
message("* SYSTEM Name: " ${CMAKE_SYSTEM_NAME})
message("* SYSTEM PROCESSOR: " ${CMAKE_SYSTEM_PROCESSOR})
message("* BUILD SYSTEM: " ${CMAKE_GENERATOR})
message("* BUILD TYPE: " ${CMAKE_BUILD_TYPE})
message("* C COMPILER: " ${CMAKE_C_COMPILER})
message("* CXX COMPILER: " ${CMAKE_CXX_COMPILER})
message("* C FLAGS: " ${CMAKE_C_FLAGS})
message("* CXX FLAGS: " ${CMAKE_CXX_FLAGS})
message("* EXE LINKER FLAGS: " ${CMAKE_EXE_LINKER_FLAGS})
message("* SHARED LINKER FLAGS: " ${CMAKE_SHARED_LINKER_FLAGS})
message("* MODULE LINKER FLAGS: " ${CMAKE_MODULE_LINKER_FLAGS})
message("* LIBRARY OUTPUT PATH: " ${LIBRARY_OUTPUT_PATH})
message("* EXECUTABLE OUTPUT PATH: " ${EXECUTABLE_OUTPUT_PATH})
message("***********************************************")

add_subdirectory(postgresql-9.5.3)
#add_subdirectory(Hash)
#add_subdirectory(demo)


