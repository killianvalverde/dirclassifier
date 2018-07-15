cmake_minimum_required(VERSION 3.15)

project(dirclassifier)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set(SOURCE_FILES
        src/main.cpp
        src/program.cpp
        src/program.hpp
)

add_executable(dirclassifier ${SOURCE_FILES})
target_link_libraries(dirclassifier -lspeed -lstdc++fs)
install(TARGETS dirclassifier DESTINATION bin)
