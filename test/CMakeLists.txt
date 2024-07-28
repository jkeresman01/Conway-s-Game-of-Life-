cmake_minimum_required(VERSION 3.10)
project(ConwaysGameOfLifeTests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})

include_directories(../src/headers)

set(SOURCE_FILES
    ../src/Background.cpp
    ../src/Button.cpp
    ../src/Cell.cpp
    ../src/GameOfLife.cpp
    ../src/Map.cpp
    ../src/Title.cpp
)

set(TEST_FILES
    ButtonTest.cpp
    CellTest.cpp
    MapTest.cpp
)

add_executable(runTests ${SOURCE_FILES} ${TEST_FILES})

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread sfml-graphics sfml-window sfml-system)
