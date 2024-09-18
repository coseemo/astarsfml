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
    void run(sf::RenderWindow &window) const;
    void render(sf::RenderWindow &window) const;
    void processEvents(sf::RenderWindow &window) const;
    void update(std::vector<Tile*>::iterator &it, std::vector<Tile*>::iterator end) const;

private:
    Map& world;
    Character& character;
    Tile& startTile;
    Tile& endTile;
};

#endif // ASTARSEARCH_GAME_H
