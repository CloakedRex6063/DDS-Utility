cmake_minimum_required(VERSION 3.11)

project(DDS LANGUAGES CXX)

add_library(DDS INTERFACE)
target_include_directories(DDS INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
