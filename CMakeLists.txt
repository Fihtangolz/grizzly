cmake_minimum_required(VERSION 3.9)
project(grizzly)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.[c,h])
foreach(source_file ${source_files})
    message("Found file to build: " ${source_file})
endforeach()

add_executable(grizzly ${source_files})