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
    std::vector<Tile> tiles;
    int width, height;
    sf::Texture grassTexture;
    sf::Texture wallTexture;
    std::mt19937 rng;

    Map(int width, int height);
    int GetMap( int x, int y );
    int generateRandomCost();
    void draw(sf::RenderWindow &window);
};

#endif //ASTARSEARCH_MAP_H
