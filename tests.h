//
// Created by cosim on 08/08/2024.
//

#ifndef ASTARSEARCH_TESTS_H
#define ASTARSEARCH_TESTS_H
#include "map.h"
#include "character.h"
#include <vector>
#include <tuple>
#include <random>

// Dichiarazione degli array globali di mappe e personaggi
extern std::vector<Map> testMaps;
extern std::vector<std::tuple<Tile, Tile>> testTiles;
extern std::mt19937 rng;

// Funzione per ottenere un tile random
Tile* getRandomValidTile(Map& map, std::mt19937& ran);

// Funzione per inizializzare i dati di test
void initializeTestData();



#endif// ASTARSEARCH_TESTS_H
