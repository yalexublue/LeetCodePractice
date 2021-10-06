cmake_minimum_required(VERSION 2.8.12)
project (LeetCodeGrind)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        )

add_executable(${PROJECT_NAME}_bin ${SOURCES})