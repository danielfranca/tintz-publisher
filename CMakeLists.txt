cmake_minimum_required (VERSION 2.6)
project(TintzPublisher)

ADD_DEFINITIONS(-std=c++14)

set (TintzPublisher_VERSION_MAJOR 0)
set (TintzPublisher_VERSION_MINOR 1)

add_executable(TintzPublisher src/main.cpp src/CBZPublisher.cpp)

find_library(ZIPPER Zipper-static /usr/local/lib)
find_library(MINIZIP minizip /usr/local/lib)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.63.0 COMPONENTS filesystem system)

if(Boost_FOUND)
INCLUDE_DIRECTORIES(/usr/local/include)
TARGET_LINK_LIBRARIES(TintzPublisher ${MINIZIP} ${ZIPPER} ${Boost_LIBRARIES})
endif()
