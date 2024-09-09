#include <iostream>
#include "Game.h"
#include "tests.h"

int main() {
    // Inizializzo i dati di test
    initializeTestData();

    // Itero attraverso le mappe e le coppie di tile di test
    for (size_t i = 0; i < testMaps.size(); ++i) {
        Map& map = testMaps[i];
        Tile& startTile = std::get<0>(testTiles[i]);
        Tile& endTile = std::get<1>(testTiles[i]);

        // Creo un personaggio con il tile di partenza
        Character character(&startTile, map);

        // Creo un'istanza di Game e avvia il gioco
        Game game(map, character, startTile, endTile);
        game.run();

        std::cout << "Test " << i + 1 << " completato." << std::endl;
    }

    return 0;
}
