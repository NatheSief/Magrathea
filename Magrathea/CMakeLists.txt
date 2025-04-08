cmake_minimum_required(VERSION 3.5)
project(MyRaylibGame C)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

add_executable(my_game src/main.c)
target_link_libraries(my_game raylib)
