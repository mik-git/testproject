cmake_minimum_required(VERSION 2.8)

project(mtfind)
find_package (Threads)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -lpthread -DNDEBUG -DEIGEN_MPL2_ONLY")
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall -lpthread -DEIGEN_MPL2_ONLY")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O0 -lpthread -I/usr/include/freetype2 -DNDEBUG -DEIGEN_MPL2_ONLY")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -lpthread -I/usr/include/freetype2 -DEIGEN_MPL2_ONLY")
set(SRC_LIST main.cpp worker.cpp worker.h)
add_executable(${PROJECT_NAME} ${SRC_LIST})

