//
// Creato da cosim il 08/08/2024.
//

#ifndef ASTARSEARCH_CHARACTER_H
#define ASTARSEARCH_CHARACTER_H
#include "Tile.h"
#include "map.h"

class Character {

public:
    Character(Tile *startTile, Map &world);
    void moveTo(Tile* targetTile, bool startend);
    void draw(sf::RenderWindow &window) const;
    Tile* getCurrentTile() const;

private:
    Tile* currentTile;
    Map& world;
    sf::CircleShape shape;
};

#endif //ASTARSEARCH_CHARACTER_H
