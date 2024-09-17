#include "game.h"
#include "astar.h"
#include <vector>

Game::Game(Map& map, Character& character, Tile& startTile, Tile& endTile)
        :
          world(map),
          character(character),
          startTile(startTile),
          endTile(endTile) {world.limits(startTile, endTile);}

// Avvio il ciclo di gioco
void Game::run(sf::RenderWindow &window) const {
    std::vector<Tile*> path = astar(startTile, endTile, world);
    auto it = path.begin();
    auto end = path.end();

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(7.f / 60.f);

    while (window.isOpen()) {
        processEvents(window);
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents(window);
            update(it, end);
        }
        render(window);
    }
}

void Game::processEvents(sf::RenderWindow &window) const {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::render(sf::RenderWindow &window) const {
    window.clear();
    world.draw(window);
    character.draw(window);
    window.display();
}


void Game::update(std::vector<Tile*>::iterator &it, std::vector<Tile*>::iterator end) const{
    if (it != end) {
        if (**it != startTile && **it != endTile) {
            character.moveTo(*it, false);
        } else {
            character.moveTo(*it, true);
        }
        ++it;
    }
}

