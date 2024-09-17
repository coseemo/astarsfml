//
// Creato da cosim il 08/08/2024.
//
#include <iostream>
#include "map.h"


Map::Map(int width, int height, std::vector<int> mapCosts) : width(width), height(height) {
    // Carico le texture
    loadTextures();

    tiles.reserve(width * height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int cost = mapCosts[(y * width) + x];
            if (cost == 9)
                tiles.emplace_back(x, y, cost, &wallTexture);
            else
                tiles.emplace_back(x, y, cost, &grassTexture);
        }
    }
}

void Map::loadTextures() {
    if (!wallTexture.loadFromFile("textures/wall.png")) {
        throw std::runtime_error("Impossibile caricare la texture wall.png");
    }
    if (!grassTexture.loadFromFile("textures/grass.png")) {
        throw std::runtime_error("Impossibile caricare la texture grass.png");
    }
    if (!stepTexture.loadFromFile("textures/step.png")) {
        throw std::runtime_error("Impossibile caricare la texture step.png");
    }
    if (!limitTexture.loadFromFile("textures/limit.png")) {
        throw std::runtime_error("Impossibile caricare la texture limit.png");
    }

    else
        std::cout << "Texture importate correttamente" << std::endl;
}

// Funzione per disegnare la mappa nella finestra del gioco
void Map::draw(sf::RenderWindow &window) const {
    sf::Font font;  // Carattere per mostrare il costo dei vari tile

    window.setActive(true);  // Rendo attiva la finestra per il rendering

    // Carico il font per i costi dei tile
    if (!font.loadFromFile("C:/Users/cosim/CLionProjects/astarsearch/font/gothic.ttf")) {
        throw std::runtime_error("Impossibile caricare il font gothic.ttf");
    }

    sf::Text costText;  // Oggetto di testo per visualizzare il costo delle tessere
    costText.setFont(font);
    costText.setCharacterSize(40);
    costText.setFillColor(sf::Color::Black);

    // Ciclo per disegnare tutte le tessere e mostrare i loro costi
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            Tile tile = tiles[(y * width) + x];  // Prendo il tile corrente
            tile.draw(window);  // Lo disegno
            costText.setString(std::to_string(tile.getCost()));  // Imposto il testo con il costo del tile
            costText.setPosition(tile.getShape().getPosition().x + 15, tile.getShape().getPosition().y + 10);  // Posiziono il testo
            window.draw(costText);  // Disegno il testo
        }
    }
}

// Funzione che restituisce il costo del tile nella posizione (x, y)
int Map::getMap(int x, int y)
{
    // Controllo se le coordinate sono fuori dai limiti della mappa
    if( x < 0 || x >= width || y < 0 || y >= height ) {
        return 9;  // Restituisco 9 se è fuori dai limiti (lo considero non percorribile)
    }

    return tiles[(y*width)+x].getCost();  // Restituisco il costo del tile
}

// Funzione che cambia la texture del tile quando viene percorsa
void Map::walked(Tile& tile) {
    tile.getShape().setTexture(&stepTexture);
}

// Funzione che cambia la texture della tessera a "limite"
void Map::limits(Tile& startTile, Tile& endTile) {
    startTile.getShape().setTexture(&limitTexture);
    endTile.getShape().setTexture(&limitTexture);
}

// Funzione che imposta una tessera come muro
void Map::setWall(Tile& tile){
    tile.setCost(9);  // Imposto il costo della tessera a 9 (non percorribile)
    tile.getShape().setTexture(&wallTexture);  // Cambio la texture
    tile.getShape().setFillColor(sf::Color(200,0,0, 200));  // Imposto un colore per distinguere il muro aggiunto
}


int Map::getWidth() const {
    return width;
}

int Map::getHeight() const {
    return height;
}

std::vector<Tile>& Map::getTiles() {
    return tiles;
}
