cmake_minimum_required(VERSION 3.22)
project(rxcpp)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/conan_build/conanbuildinfo.cmake)
    message("conan setup")
    include(${CMAKE_CURRENT_SOURCE_DIR}/conan_build/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_OSX_ARCHITECTURES x86_64)

add_executable(rxcpp main.cpp)
target_link_libraries(rxcpp ${CONAN_LIBS})