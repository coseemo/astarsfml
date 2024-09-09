//
// Created by cosim on 08/08/2024.
//
#include "Tile.h"

Tile::Tile(int x, int y, int cost) : x(x), y(y), cost(cost){

    shape.setSize(sf::Vector2f(30, 30));
    shape.setPosition(x * 30, y * 30);
}

void Tile::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

