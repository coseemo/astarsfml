//
// Created by cosim on 08/08/2024.
//

#ifndef ASTARSEARCH_MAP_H
#define ASTARSEARCH_MAP_H
#include "Tile.h"
#include <random>
#include <random>

class Map {

public:

    Map(int width, int height, std::vector<int> mapCosts);
    int getWidth() const;
    int getHeight() const;
    void walked(Tile& tile);
    void limits(Tile& startTile, Tile& endTile);
    void setWall(Tile& tile);
    int getMap(int x, int y);
    std::vector<Tile> & getTiles();
    void draw(sf::RenderWindow &window) const;

private:

    int width, height;
    std::vector<Tile> tiles;
    sf::Texture wallTexture;
    sf::Texture grassTexture;
    sf::Texture stepTexture;
    sf::Texture limitTexture;

    void loadTextures();

};



#endif //ASTARSEARCH_MAP_H
