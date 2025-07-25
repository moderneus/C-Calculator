cmake_minimum_required(VERSION 3.20)
project(Calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

find_package(fmt REQUIRED)

add_executable(Calculator

    src/Calculator.cpp
    src/Operations.cpp
    src/CommandMap.cpp
    src/History.cpp
    src/Utils/CheckUtils.cpp
    src/Utils/PrintUtils.cpp
    src/Utils/RequestUtils.cpp
    src/Utils/Utils.cpp

)

target_include_directories(Calculator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers)
target_link_libraries(Calculator PRIVATE fmt::fmt)

