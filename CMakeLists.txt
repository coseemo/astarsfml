cmake_minimum_required(VERSION 3.0)
project(astarsearch)

# Aggiungo la directory di SFML
set(SFML_DIR "C:/SFML/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Imposto l'eseguibile del progetto e aggiungo i file sorgente
add_executable(astarsearch
        astar.cpp
        character.cpp
        game.cpp
        game.h
        main.cpp
        stlastar.h
        fsa.h
        map.cpp
        map.h
        Tile.cpp
        Tile.h
        character.h
        tests.cpp
        astar.h
        tests.h
)

# Collego SFML alle librerie del progetto
target_link_libraries(astarsearch sfml-graphics sfml-window sfml-system)
