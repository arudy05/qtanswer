cmake_minimum_required(VERSION 3.16)

project(qtanswer VERSION 0.3.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(nlohmann_json 3.12.0 REQUIRED)
qt_standard_project_setup()

add_library(json)
target_link_libraries(json PRIVATE nlohmann_json::nlohmann_json)

add_subdirectory(src)

# THIS SECTION is adapted from https://gist.github.com/Tordan/c4d4d14aac0e85ebf7122ed2189ea387
add_custom_command(
    OUTPUT
        ${CMAKE_BINARY_DIR}/version.h
        ALL
    COMMAND
        ${CMAKE_COMMAND} -D PROJECT_VERSION=${PROJECT_VERSION} -D IN_FILE=${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in -D OUT_FILE=${CMAKE_CURRENT_SOURCE_DIR}/src/version.h -P ${CMAKE_CURRENT_SOURCE_DIR}/version.cmake
    WORKING_DIRECTORY
        ${CMAKE_SOURCE_DIR}
)

file(WRITE ${CMAKE_BINARY_DIR}/version.h)

add_custom_target(
    generate_version_header
        ALL
    COMMAND
        ${CMAKE_COMMAND} -D PROJECT_VERSION=${PROJECT_VERSION} -D IN_FILE=${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in -D OUT_FILE=${CMAKE_CURRENT_SOURCE_DIR}/src/version.h -P ${CMAKE_CURRENT_SOURCE_DIR}/version.cmake
    WORKING_DIRECTORY
        ${CMAKE_SOURCE_DIR}
)
########
