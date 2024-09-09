//
// Created by cosim on 08/08/2024.
//
#include "map.h"

Map::Map(int width, int height) : width(width), height(height) {
    tiles.reserve(width * height); // Riservo spazio per evitare riallocazioni multiple

    std::random_device rd;
    rng = std::mt19937(rd());

    if (!grassTexture.loadFromFile("C:/Users/cosim/CLionProjects/astarsearch/textures/grass.png")) {
        throw std::runtime_error("Impossibile caricare la texture grass.png");
    }

    if (!wallTexture.loadFromFile("C:/Users/cosim/CLionProjects/astarsearch/textures/wall.png")) {
        throw std::runtime_error("Impossibile caricare la texture wall.png");
    }

    if (!stepTexture.loadFromFile("C:/Users/cosim/CLionProjects/astarsearch/textures/step.png")) {
        throw std::runtime_error("Impossibile caricare la texture step.png");
    }

    for (int y = 0; y < width; ++y) {
        for (int x = 0; x < height; ++x) {
            int cost = generateRandomCost();
            tiles.emplace_back(x, y, cost);
            if(cost == 9)
                tiles[(y*width)+x].shape.setTexture(&wallTexture);
            else
                tiles[(y*width)+x].shape.setTexture(&grassTexture);
        }
    }
}

void Map::draw(sf::RenderWindow &window) {
    sf::Font font;

    window.setActive(true);

    if (!font.loadFromFile("C:/Users/cosim/CLionProjects/astarsearch/font/gothic.ttf")) {
        throw std::runtime_error("Impossibile caricare il font gothic.ttf");
    }

    sf::Text costText;
    costText.setFont(font);
    costText.setCharacterSize(20);
    costText.setFillColor(sf::Color::Black);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            Tile &tile = tiles[(y * width) + x];


            tile.draw(window);


            costText.setString(std::to_string(tile.cost));


            costText.setPosition(tile.shape.getPosition().x + 15, tile.shape.getPosition().y + 10);


            window.draw(costText);
        }
    }
}


int Map::GetMap( int x, int y )
{
    if( x < 0 ||
        x >= width||
        y < 0 ||
        y >= height
            )
    {
        return 9;
    }

    return tiles[(y*width)+x].cost;
}

int Map::generateRandomCost() {
    std::uniform_int_distribution<int> dist(0, 9);
    return dist(rng);
}

void Map::walked(Tile *tile) {
    tile->shape.setTexture(&stepTexture);
}