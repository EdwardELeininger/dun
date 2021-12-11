cmake_minimum_required (VERSION 3.10.2)

project(dun)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(src)

add_executable(dun dun.c)

target_link_libraries(dun PRIVATE config)
target_link_libraries(dun PRIVATE noise)
target_link_libraries(dun PRIVATE stack)
target_link_libraries(dun PRIVATE entities)

