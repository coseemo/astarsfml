//
// Created by cosim on 08/08/2024.
//

#ifndef ASTARSEARCH_MAP_H
#define ASTARSEARCH_MAP_H
#include "Tile.h"
#include <random>
#include <random>

extern sf::Texture grassTexture;
extern sf::Texture wallTexture;
extern sf::Texture stepTexture;

void loadTextures();

class Map {

public:
    std::vector<Tile> tiles;
    int width, height;
    std::mt19937 rng;

    Map(int width, int height);
    int GetMap( int x, int y );
    int generateRandomCost();
    void draw(sf::RenderWindow &window);
    void walked(Tile *tile);
    static void limits(Tile *tile);
    static void setwall(Tile *tile);

};



#endif //ASTARSEARCH_MAP_H
