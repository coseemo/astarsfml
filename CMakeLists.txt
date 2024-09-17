cmake_minimum_required(VERSION 3.0)
project(astarsearch)

# Imposto la directory di SFML
set(SFML_DIR "C:/SFML/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Aggiungo la directory include di SFML
include_directories("C:/SFML/include")

# Imposto i file sorgente del progetto
set(SOURCES
        src/astar.cpp
        src/astar.h
        src/Tile.cpp
        src/Tile.h
        src/map.cpp
        src/map.h
        src/character.cpp
        src/character.h
        src/game.h
        src/game.cpp
        src/main.cpp
)

# Creo l'eseguibile principale
add_executable(astarsearch ${SOURCES})

# Crea una libreria core separata per condividere il codice con i test
add_library(core ${SOURCES})

# Collego SFML al progetto
target_link_libraries(astarsearch sfml-graphics sfml-window sfml-system core)

# Abilito il framework di testing
enable_testing()

# Aggiungo la subdirectory per i test
add_subdirectory(tests)
