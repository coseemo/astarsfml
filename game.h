//
// Created by cosim on 08/08/2024.
//

#ifndef ASTARSEARCH_GAME_H
#define ASTARSEARCH_GAME_H
#include <SFML/Graphics.hpp>
#include "character.h"
#include "map.h"
#include <memory>
#include <array>

class Game {

public:
    Game(Map& map, Character& character, Tile& startTile, Tile& endTile);
    void run();

private:
    sf::RenderWindow window;
    Map& world;
    Character& character;
    Tile& startTile;
    Tile& endTile;

    void processEvents();
    void update(std::vector<Tile*>::iterator &it, std::vector<Tile*>::iterator end);
    void render();
};



#endif //ASTARSEARCH_GAME_H
