//
// Created by cosim on 08/08/2024.
//

#ifndef ASTARSEARCH_ASTAR_H
#define ASTARSEARCH_ASTAR_H
#include "stlastar.h"
#include "map.h"
#include "astar.h"

class MapSearchNode{

public:
    int x;	 // the (x,y) positions of the node
    int y;
    Map* map;

    explicit MapSearchNode(int x = 0, int y = 0, Map* map = nullptr);
    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );
    size_t Hash();
    void PrintNodeInfo();

};

vector<Tile*> astar(Tile &start, Tile &end, Map &world);
#endif //ASTARSEARCH_ASTAR_H
