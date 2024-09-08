//
// Created by cosim on 08/08/2024.
//

#ifndef ASTARSEARCH_CHARACTER_H
#define ASTARSEARCH_CHARACTER_H
#include "Tile.h"
#include "map.h"


class Character {

public:

    Character(Tile* startTile);
    void moveTo(Tile* targetTile);
    void draw(sf::RenderWindow &window) const;

    Tile* currentTile;
    sf::Texture stepTexture;
    sf::CircleShape shape;
};
#endif //ASTARSEARCH_CHARACTER_H
