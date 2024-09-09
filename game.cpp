//
// Created by cosim on 13/07/2024.
//
#include <vector>
#include "game.h"
#include "astar.h"


Game::Game(Map& map, Character& character, Tile& startTile, Tile& endTile)
        : window(sf::VideoMode(600, 600), "Find A* way"),
          world(map),
          character(character),
          startTile(startTile),
          endTile(endTile)
          {}

void Game::run() {

    std::vector<Tile*> path = astar(startTile, endTile, world);
    auto it = path.begin();
    auto end = path.end();

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(5.f / 60.f);

    while (window.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(it, end);
        }
        render();
    }
}


void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(std::vector<Tile*>::iterator &it, std::vector<Tile*>::iterator end) {
    if (it != end) {
        // Sposta il personaggio e cambia la texture
        if (**it != startTile && **it != endTile) {
            character.moveTo(*it, false);
        } else {
            // Sposta il personaggio senza cambiare la texture
            character.moveTo(*it, true);
        }
        ++it;
    }
}


void Game::render() {
    window.clear();
    world.draw(window);
    character.draw(window);
    window.display();
}
