cmake_minimum_required(VERSION 3.10)
project(ConwaysGameOfLife)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(src/headers)

set(SOURCE_FILES
    src/Background.cpp
    src/ResourceManager.cpp
    src/Button.cpp
    src/Cell.cpp
    src/GameOfLife.cpp
    src/Main.cpp
    src/Map.cpp
    src/Label.cpp
)

add_executable(game-of-life ${SOURCE_FILES})

target_link_libraries(game-of-life sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET game-of-life POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/resources $<TARGET_FILE_DIR:game-of-life>/resources
)

