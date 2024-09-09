//
// Created by cosim on 08/08/2024.
//
#include "character.h"

Character::Character(Tile *startTile, Map &world) : currentTile(startTile), world(world) {

    shape.setRadius(15);
    shape.setFillColor(sf::Color::Blue);
    moveTo(startTile);
}

void Character::moveTo(Tile *targetTile) {
    world.walked(targetTile);
    currentTile = targetTile;
    shape.setPosition(targetTile->x * 30 + 15, targetTile->y * 30 + 15);
}

void Character::draw(sf::RenderWindow &window) const {
    window.setActive(true);
    window.draw(shape);
}
