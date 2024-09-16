//
// Creato da cosim il 08/08/2024.
//
#include "Tile.h"

Tile::Tile(int x, int y, int cost) : x(x), y(y), cost(cost) {
    // Imposto le dimensioni del tile a 30x30 pixel.
    shape.setSize(sf::Vector2f(30, 30));

    // Posiziono il tile sulla finestra in base alle coordinate x e y scalate di 30 (ogni tile è 30x30 pixel).
    shape.setPosition(x * 30, y * 30);
}

void Tile::draw(sf::RenderWindow &window) const {
    window.draw(shape);  // Disegno il tile
}

// Sovraccarico operatore di uguaglianza
bool Tile::operator==(const Tile& other) const {
    return (x == other.x) && (y == other.y) && (cost == other.cost);
}

// Sovraccarico operatore di disuguaglianza
bool Tile::operator!=(const Tile& other) const {
    return (x != other.x) || (y != other.y) || (cost != other.cost);
}
