//
// Creato da cosim il 08/08/2024.
//
#include "character.h"

// Costruttore della classe Character, inizializzo il personaggio sul tile di partenza
Character::Character(Tile *startTile, Map &world) : currentTile(startTile), world(world) {
    // Imposto la forma del personaggio come un cerchio con raggio 15 e colore blu
    shape.setRadius(15);
    shape.setFillColor(sf::Color::Blue);
    // Posiziono il personaggio sul tile di partenza
    moveTo(startTile, false);
}

// Metodo per muovere il personaggio su una nuova tessera
void Character::moveTo(Tile *targetTile, bool startend) {
    // Se non è il primo movimento, aggiorno il tile corrente e la posizione del personaggio
    if(!startend) {
        currentTile = targetTile;
        shape.setPosition(targetTile->x * 30 + 15, targetTile->y * 30 + 15);
        // Aggiorno la texture
        world.walked(targetTile);
    }
        // Se è il movimento di inizio/fine, imposto solo la posizione senza aggiornare la texture
    else
        shape.setPosition(targetTile->x * 30 + 15, targetTile->y * 30 + 15);
}

// Disegno il personaggio
void Character::draw(sf::RenderWindow &window) const {
    window.setActive(true);  // Attivo la finestra per il rendering
    window.draw(shape);      // Disegno la forma del personaggio
}

Tile* Character::getCurrentTile() const {
    return currentTile;
}
