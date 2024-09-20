//
// Creato da cosim il 08/08/2024.
//
#include <iostream>
#include "Tile.h"

Tile::Tile(int x, int y, int cost, sf::Texture* tileTexture) : x(x), y(y), cost(cost) {
    // Imposto le dimensioni del tile a 30x30 pixel.
    shape.setSize(sf::Vector2f(100, 100));

    // Posiziono il tile sulla finestra in base alle coordinate x e y scalate di 30 (ogni tile è 30x30 pixel).
    shape.setPosition(x * 100, y * 100);

    // Setto la texture
    shape.setTexture(tileTexture);
}

void Tile::draw(sf::RenderWindow &window) const {
    window.draw(shape);  // Disegno il tile
}

// Sovraccarico operatore di uguaglianza
bool Tile::operator==(const Tile& other) const {
    return (x == other.x) && (y == other.y) && (getCost() == other.getCost());
}

// Sovraccarico operatore di disuguaglianza
bool Tile::operator!=(const Tile& other) const {
    return (x != other.x) || (y != other.y) || (getCost() != other.getCost());
}

int Tile::getX() const {
    return x;
}

int Tile::getY() const {
    return y;
}


int Tile::getCost() const {
    return cost;
}

/*void Tile::setCost(int c) {
    Tile::cost = c;
}
*/

sf::RectangleShape& Tile::getShape(){
    return shape;
}

