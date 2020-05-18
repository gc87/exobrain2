# CMakeList.txt : CMake project for exobrain++, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_TOOLCHAIN_FILE "C:/Users/chun/App/vcpkg/scripts/buildsystems/vcpkg.cmake")
project ("exobrain2")

set(Boost_USE_STATIC_LIBS ON)
#set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME ON) 
#set(Python3_USE_STATIC_LIBS ON)

find_package(Boost REQUIRED COMPONENTS filesystem regex system python37)
find_package(RocksDB CONFIG REQUIRED)
find_package(ZLIB REQUIRED)
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Python3_INCLUDE_DIRS})

#MESSAGE(STATUS "python~1 = ${Python3_INCLUDE_DIRS}.")
#MESSAGE(STATUS "python~2 = ${Python3_LIBRARIES}.")

# Add source to this project's executable.
add_executable (exobrain2 "exobrain2.cpp" "exobrain2.h")
target_link_libraries(exobrain2 PRIVATE ${Boost_LIBRARIES} RocksDB::rocksdb ZLIB::ZLIB ${Python3_LIBRARIES})

# TODO: Add tests and install targets if needed.
