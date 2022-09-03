cmake_minimum_required(VERSION 3.22)
project(json)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)


add_executable(json main.cpp myJsonFilms.cpp myJsonFilms.h)

target_link_libraries(json PRIVATE nlohmann_json::nlohmann_json)
