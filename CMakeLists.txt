cmake_minimum_required(VERSION 3.16)

project(qtanswer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(nlohmann_json 3.12.0 REQUIRED)
qt_standard_project_setup()

add_library(json)
target_link_libraries(json PRIVATE nlohmann_json::nlohmann_json)

add_subdirectory(src)


