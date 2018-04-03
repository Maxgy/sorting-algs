cmake_minimum_required (VERSION 3.10.3)

include_directories (include)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "-O3")

set (SOURCES src/main.cc)

add_executable (run ${SOURCES})
