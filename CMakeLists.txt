cmake_minimum_required(VERSION 4.0)
project(CRaylibTemplate)

set(LANGUAGE C_STANDARD)
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)
FetchContent_Declare(
    raygui
    GIT_REPOSITORY https://github.com/raysan5/raygui.git
    GIT_TAG 4.0
)

FetchContent_MakeAvailable(raylib raygui)

add_executable(${PROJECT_NAME} ${raygui_SOURCE_DIR}/src/raygui.h)
add_subdirectory(src)
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_include_directories(${PROJECT_NAME} PRIVATE ${raygui_SOURCE_DIR}/src)
