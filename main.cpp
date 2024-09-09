#include <iostream>
#include "game.h"
#include "tests.h"

void runTest(Map &map, Tile &start, Tile &end) {
    // Ridefinisci la mappa globale e aggiorna le posizioni globali
    world_map = map;
    x_s = start.x;
    y_s = start.y;
    x_e = end.x;
    y_e = end.y;

    // Reimposta StartTile e EndTile
    StartTile = world_map.tiles[(y_s * world_map.width) + x_s];
    EndTile = world_map.tiles[(y_e * world_map.width) + x_e];

    // Reimposta il personaggio di test
    test_character = Character(&StartTile, map);

    // Inserisci qui la logica di test
    std::cout << "Esecuzione test su mappa con dimensioni (" << map.width << "x" << map.height << ")...\n";
}
int main() {
    Game game;
    game.run();
    return 0;
}

