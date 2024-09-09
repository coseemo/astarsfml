//
// Creato da cosim il 13/07/2024.
//
#include <vector>
#include "game.h"
#include "astar.h"

Game::Game(Map& map, Character& character, Tile& startTile, Tile& endTile)
        : window(sf::VideoMode(600, 600), "Find A* way"),  // Creo una finestra di 600x600 pixel
          world(map),  // Inizializzo il mondo di gioco
          character(character),  // Inizializzo il personaggio
          startTile(startTile),  // Definisco la tile di partenza
          endTile(endTile)  // Definisco il tile di arrivo
{}

// Avvio il ciclo di gioco
void Game::run() {

    // Calcolo il percorso usando l'algoritmo A* tra il tile di partenza e quello di arrivo
    std::vector<Tile*> path = astar(startTile, endTile, world);
    auto it = path.begin();  // Inizializzo l'iteratore per il percorso
    auto end = path.end();   // Definisco il punto finale dell'iteratore

    sf::Clock clock;  // Avvio l'orologio per gestire l'aggiornamento del gioco
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(5.f / 60.f);  // Tempo per ogni frame

    // Loop principale del gioco, continua fino a che la finestra è aperta
    while (window.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();  // Aggiorno il tempo trascorso
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents(); // Gestisco eventi di input
            update(it, end);  // Aggiorno lo stato del gioco in base al tempo trascorso
        }
        render();  // Renderizzo il mondo e il personaggio
    }
}

// Gestione degli eventi della finestra
void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        // Gestisco la chiusura della finestra
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

// Aggiorno lo stato del gioco spostando il personaggio lungo il percorso calcolato
void Game::update(std::vector<Tile*>::iterator &it, std::vector<Tile*>::iterator end) {
    // Finché il personaggio non è giunto a destinazione
    if (it != end) {
        // Sposto il personaggio e cambia la texture solo se non è al tile di partenza o arrivo
        if (**it != startTile && **it != endTile) {
            character.moveTo(*it, false);
        } else {
            // Sposto il personaggio senza cambiare la texture (partenza o fine)
            character.moveTo(*it, true);
        }
        ++it;  // Passo al prossimo tile del percorso
    }
}

// Renderizzo la mappa e il personaggio nella finestra di gioco
void Game::render() {
    window.clear();  // Pulisco la finestra
    world.draw(window);  // Disegno il mondo (la mappa)
    character.draw(window);  // Disegno il personaggio
    window.display();  // Mostro il risultato del rendering
}
