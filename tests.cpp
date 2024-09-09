//
// Created by cosim on 08/08/2024.
//
#include "tests.h"
#include <tuple>
#include <random>

// Definizione degli array globali
std::vector<Map> testMaps;
std::vector<std::tuple<Tile, Tile>> testTiles;
std::mt19937 rng;

// Funzione per inizializzare i dati di test
void initializeTestData() {

    std::random_device rd;
    rng = std::mt19937(rd());

    // Setto un numero N di test
    int N = 10;

    // Inizializzo N mappe di test random
    for (int i = 0; i < N; ++i) {
        testMaps.emplace_back(Map(20,20));
    }

    // Inizializzo N coppie di tile di partenza e di arrivo
    for (int i = 0; i < N; ++i) {
        Tile* startTile = getRandomValidTile(testMaps[i], rng);
        Tile* endTile = getRandomValidTile(testMaps[i], rng);

        while (*startTile == *endTile) {
            endTile = getRandomValidTile(testMaps[i], rng);
        }

        testMaps[i].limits(startTile);
        testMaps[i].limits(endTile);

        // La penultima mappa avrà che il tile partenza sarà su un muro, dunque dovrà fallire
        if(i == N-2)
            testMaps[i].setwall(startTile);

        // L'ultima mappa avrà che il tile destinazione sarà su un muro, dunque dovrà fallire
        if(i == N-1)
            testMaps[i].setwall(endTile);

        testTiles.emplace_back(*startTile, *endTile);
    }

}

// Funzione per ottenere un tile casuale valido
Tile* getRandomValidTile(Map& map, std::mt19937& ran) {
    std::uniform_int_distribution<int> distX(0, map.width - 1);
    std::uniform_int_distribution<int> distY(0, map.height - 1);

    Tile* tile = NULL;

    // Continuo a cercare finché non trovo un tile valido
    do {
        int x = distX(ran);
        int y = distY(ran);
        tile = &map.tiles[y * map.width + x];
    } while (tile->cost == 9); // Escludo i muri (considerando che 9 è il costo dei muri)

    return tile;
}