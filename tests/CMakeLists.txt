cmake_minimum_required(VERSION 3.10)
project(test)

# Add the directory containing Google Test
add_subdirectory(lib)

# Define the directory for Google Test headers
set(GTEST_SRC_DIRECTORY lib/googletest)

# Include directories
include_directories(${GTEST_SRC_DIRECTORY}/include ${GTEST_SRC_DIRECTORY} sfml/include)

# List of source files for the project
set(SOURCE_FILES
        ../src/astar.cpp
        ../src/Tile.cpp
        ../src/map.cpp
        ../src/character.cpp
        ../src/game.cpp
)

# List of test files
set(TEST_FILES
        unitTest.cpp
        unitTest.cpp
)

# Include SFML directories
include_directories(${CMAKE_SOURCE_DIR}/sfml/include)

# Link directories for SFML
link_directories(${CMAKE_SOURCE_DIR}/sfml/lib)

# Create the executable for the tests
add_executable(runTests ${TEST_FILES} ${SOURCE_FILES})

# Link the SFML libraries
target_link_libraries(runTests
        sfml-graphics
        sfml-window
        sfml-system
        sfml-network
        sfml-audio
        gtest
        gtest_main
)

# Specify the C++ standard
set_target_properties(runTests PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)
