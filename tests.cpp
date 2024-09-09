//
// Created by cosim on 08/08/2024.
//
#include "tests.h"

int MAP_WIDTH = 20;
int MAP_HEIGHT = 20;
Map world_map = Map(MAP_WIDTH, MAP_HEIGHT);

int x_s = 0;
int y_s = 0;

int x_e = 19;
int y_e = 19;

Tile &StartTile = world_map.tiles[(y_s*world_map.width)+x_s];
Tile &EndTile = world_map.tiles[(y_e*world_map.width)+x_e];

Character test_character = Character(&StartTile, world_map);

