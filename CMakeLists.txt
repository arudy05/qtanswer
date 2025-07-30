cmake_minimum_required(VERSION 3.16)

project(qtanswer VERSION 0.3.1 LANGUAGES CXX)

option(GH_ACTIONS "Enable stuff to make this run on GitHub Actions" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

if(GH_ACTIONS)
    include(FetchContent)
    FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
    FetchContent_MakeAvailable(json)
    add_library (json)
    target_include_directories (JSON PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")
else()
    find_package(nlohmann_json 3.12.0 REQUIRED)
endif()

add_subdirectory(src)
add_subdirectory(src/wrappers)
add_subdirectory(src/interface)

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

install(TARGETS qtanswer DESTINATION bin)
