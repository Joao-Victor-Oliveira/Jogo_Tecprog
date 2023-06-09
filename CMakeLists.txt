cmake_minimum_required(VERSION 3.2.6)
project(Jogo_Tecprog)

set(CMAKE_CXX_STANDARD 17)

# Find the SFML library
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Define the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Define compilation flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Add include directories
include_directories(include)

# Create a list of all source and header files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/**/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h" "include/**/*.h")

# Create the target executable and link with SFML libraries
add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

# Add the Google Test library and create the test executable
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create a list of all test source files
file(GLOB_RECURSE TEST_SOURCES "testes/*.cpp" "testes/**/*.cpp")

# Create the test executable and link with SFML and Google Test libraries
add_executable(testes ${TEST_SOURCES} ${SOURCES} ${HEADERS})
target_link_libraries(testes ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(testes sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

# Add include and src directories as include directories for the targets
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/src")
target_include_directories(testes PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/src")

# Link the SFML library to every file, directory, and subdirectory in the project
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
target_link_libraries(testes sfml-system sfml-window sfml-graphics sfml-network sfml-audio)