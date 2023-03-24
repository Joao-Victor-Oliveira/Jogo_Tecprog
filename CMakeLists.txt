cmake_minimum_required(VERSION 3.5)
project(Jogo_Tecprog)

set(CMAKE_CXX_STANDARD 11)

# Define as pastas de origem e inclusão
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

# Encontre a biblioteca SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Define o diretório de saída do executável
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Define as flags de compilação
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Adiciona as pastas de includes
include_directories(include)
include_directories(${SFML_INCLUDE_DIR})

# Cria o executável alvo e link com as bibliotecas SFML
add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

# Adiciona a biblioteca do Google Test e cria o executável de testes
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
file(GLOB_RECURSE TEST_SOURCES "testes/*.cpp")
add_executable(testes ${TEST_SOURCES} ${SOURCES} ${HEADERS})
target_link_libraries(testes ${GTEST_BOTH_LIBRARIES} pthread)

