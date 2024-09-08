//
// Created by cosim on 08/08/2024.
//
#include "character.h"

Character::Character(Tile* startTile) : currentTile(startTile) {
    if (!stepTexture.loadFromFile("C:/Users/cosim/CLionProjects/astarsearch/textures/step.png")) {
        throw std::runtime_error("Impossibile caricare la texture grass.png");
    }
    shape.setRadius(15);
    shape.setFillColor(sf::Color::Blue);
    startTile->shape.setTexture(&stepTexture);
    moveTo(startTile);
}

void Character::moveTo(Tile *targetTile) {
    currentTile = targetTile;
    shape.setPosition(targetTile->x * 30 + 15, targetTile->y * 30 + 15);
    currentTile->shape.setTexture(&stepTexture);
}

void Character::draw(sf::RenderWindow &window) const {
    window.draw(shape);
}
