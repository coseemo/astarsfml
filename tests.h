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

extern std::vector<Map> testMaps;
extern std::vector<std::tuple<Tile, Tile>> testTiles;
extern std::mt19937 rng;

Tile* getRandomValidTile(Map& map, std::mt19937& ran);

void initializeTestData();



#endif// ASTARSEARCH_TESTS_H
