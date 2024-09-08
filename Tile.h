//
// Created by cosim on 08/08/2024.
//

#ifndef ASTARSEARCH_TILE_H
#define ASTARSEARCH_TILE_H
#include <SFML/graphics.hpp>

class Tile{
public:
    int x, y, cost;
    sf::RectangleShape shape;

    Tile(int x, int y, int cost);
    void draw(sf::RenderWindow &window);
};
#endif //ASTARSEARCH_TILE_H
