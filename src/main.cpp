//
// Created by cosim on 17/09/2024.
//
#include <iostream>
#include "game.h"

int main() {

    std::vector<int> Costsmap =
            {0, 1, 9, 6, 7,
             0, 3, 9, 0, 1,
             9, 6, 0, 0, 3,
             4, 6, 9, 0, 3,
             9, 6, 9, 0, 0};

    Map world = Map(5, 5, Costsmap);
    Tile& start = world.getTiles()[0];
    Tile& end = world.getTiles()[24];
    world.limits(start, end);
    sf::RenderWindow window(sf::VideoMode(500, 500), "Find A* way");
    Character ash = Character(&start, world);
    Game Games(world, ash, start, end);
    Games.run(window);

    return 0;
}