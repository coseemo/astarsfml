//
// Created by cosim on 08/08/2024.
//
#ifndef ASTARSEARCH_TILE_H
#define ASTARSEARCH_TILE_H
#include <SFML/Graphics.hpp>

class Tile{

public:
    Tile(int x, int y, int cost, sf::Texture* texture);
    void draw(sf::RenderWindow &window) const;
    bool operator==(const Tile& other) const;
    bool operator!=(const Tile& other) const;
    int getX() const;
    int getY() const;
    int getCost() const;
    sf::RectangleShape& getShape();
    //void setCost(int cost);

private:
    int x, y, cost;
    sf::RectangleShape shape;
};
#endif //ASTARSEARCH_TILE_H
