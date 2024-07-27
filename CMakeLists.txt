cmake_minimum_required(VERSION 3.10)
project(ConwaysGameOfLife)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(source/headers)

set(SOURCE_FILES
    source/Background.cpp
    source/Button.cpp
    source/Cell.cpp
    source/GameOfLife.cpp
    source/Main.cpp
    source/Map.cpp
    source/Title.cpp
)

add_executable(game-of-life ${SOURCE_FILES})

target_link_libraries(game-of-life sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET game-of-life POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/source/resources $<TARGET_FILE_DIR:game-of-life>/resources
)

