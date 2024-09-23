#include "gtest/gtest.h"
#include "../src/astar.h"

// Test per mappa con percorso valido 1
TEST(AStarTest, ValidPath1) {
    cout << "TEST 1 - PERCORSO VALIDO 1\n" << endl;
    std::vector<int> Costsmap =
            {0, 7, 9, 6, 7,
             2, 1, 9, 9, 1,
             9, 0, 0, 0, 8,
             4, 6, 9, 5, 7,
             9, 6, 9, 0, 0};
    Map world(5, 5, Costsmap);
    Tile& start = world.getTiles()[0];
    Tile& end = world.getTiles()[24];
    std::vector<Tile*> calculatedPath = astar(start, end, world);

    // Inzializzo il cammino minimo esatto
    std::vector<Tile*> expectedPath;
    expectedPath.push_back(world.getTile(0, 0));
    expectedPath.push_back(world.getTile(1, 0));
    expectedPath.push_back(world.getTile(1, 1));
    expectedPath.push_back(world.getTile(2, 1));
    expectedPath.push_back(world.getTile(2, 2));
    expectedPath.push_back(world.getTile(2, 3));
    expectedPath.push_back(world.getTile(3, 3));
    expectedPath.push_back(world.getTile(4, 3));
    expectedPath.push_back(world.getTile(4, 4));

    // Inizializzo una variabile in cui memorizzo il costo del percorso calcolato
    int calculatedPathCost = 0;
    for (Tile* tile : calculatedPath) {
        calculatedPathCost += tile->getCost();
    }

    // Inizializzo una variabile in cui memorizzo il costo del percorso minimo
    // Cammino atteso:(0,0) -> (1,0) -> (1,1) -> (2,1) -> (2,2) -> (2,3) -> (3,3) -> (4,3) -> (4,4)
    int expectedPathCost = 0 + 2 + 1 + 0 + 0 + 0 + 5 + 0 + 0; // = 8



    ASSERT_EQ(expectedPath.size(), calculatedPath.size()); // Confronto la lunghezza tra i due cammini
    for(int i = 0; i < expectedPath.size(); ++i){
        ASSERT_EQ(expectedPath[i], calculatedPath[i]); // Confronto i cammini in sé per sé
    }
    ASSERT_EQ(calculatedPathCost, expectedPathCost); // Il percorso deve avere il costo minimo
    ASSERT_FALSE(calculatedPath.empty());  // Il percorso non deve essere vuoto
    ASSERT_EQ(calculatedPath.front(), &start);  // Il percorso deve iniziare dal tile di partenza
    ASSERT_EQ(calculatedPath.back(), &end);  // Il percorso deve finire al tile di arrivo

    cout <<"Il percorso corrisponde a quello minimo" << endl;
    cout << "---------------------------------------\n\n";
}

// Test per mappa con percorso valido 2
TEST(AStarTest, ValidPath2) {
    cout << "TEST 2 - PERCORSO VALIDO 2\n" << endl;
    std::vector<int> Costsmap =
            {1, 1, 9, 1, 9,
             9, 1, 9, 1, 9,
             1, 1, 1, 1, 9,
             9, 9, 9, 1, 9,
             1, 1, 1, 1, 1};
    Map world(5, 5, Costsmap);
    Tile& start = world.getTiles()[0];
    Tile& end = world.getTiles()[24];
    std::vector<Tile*> calculatedPath = astar(start, end, world);

    // Inzializzo il cammino minimo esatto
    std::vector<Tile*> expectedPath;
    expectedPath.push_back(world.getTile(0, 0));
    expectedPath.push_back(world.getTile(0, 1));
    expectedPath.push_back(world.getTile(1, 1));
    expectedPath.push_back(world.getTile(2, 1));
    expectedPath.push_back(world.getTile(2, 2));
    expectedPath.push_back(world.getTile(2, 3));
    expectedPath.push_back(world.getTile(3, 3));
    expectedPath.push_back(world.getTile(4, 3));
    expectedPath.push_back(world.getTile(4, 4));

    // Inizializzo una variabile in cui memorizzo il costo del percorso calcolato
    int calculatedPathCost = 0;
    for (Tile* tile : calculatedPath) {
        calculatedPathCost += tile->getCost();
    }

    // Inizializzo una variabile in cui memorizzo il costo del percorso minimo
    // Il cammino atteso:(0,0) -> (0,1) -> (1,1) -> (2,1) -> (2,2) -> (2,3) -> (3,3) -> (4,3) -> (4,4)
    int expectedPathCost = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1; // = 9

    ASSERT_EQ(expectedPath.size(), calculatedPath.size()); // Confronto la lunghezza tra i due cammini
    for(int i = 0; i < expectedPath.size(); ++i){
        ASSERT_EQ(expectedPath[i], calculatedPath[i]); // Confronto i cammini in sé per sé
    }
    ASSERT_EQ(calculatedPathCost, expectedPathCost); // Il percorso deve avere il costo minimo
    ASSERT_FALSE(calculatedPath.empty());  // Il percorso non deve essere vuoto
    ASSERT_EQ(calculatedPath.front(), &start);  // Il percorso deve iniziare dal tile di partenza
    ASSERT_EQ(calculatedPath.back(), &end);  // Il percorso deve finire al tile di arrivo


    cout <<"Il percorso corrisponde a quello minimo" << endl;
    cout << "---------------------------------------\n\n";
}

// Test per inizio su un muro
TEST(AStarTest, StartOnWall) {
    cout << "TEST 3 - PARTENZA SUL MURO\n" << endl;
    std::vector<int> Costsmap =
            {9, 1, 9, 6, 7,
             0, 3, 9, 0, 1,
             9, 6, 0, 0, 3,
             4, 6, 9, 0, 3,
             9, 6, 9, 0, 0};
    Map world(5, 5, Costsmap);
    Tile& start = world.getTiles()[0];  // Inizio su un muro
    Tile& end = world.getTiles()[24];
    std::vector<Tile*> path = astar(start, end, world);
    ASSERT_TRUE(path.empty());  // Non ci deve essere alcun percorso valido
    cout << "---------------------------------------\n\n";
}

// Test per fine su un muro
TEST(AStarTest, EndOnWall) {
    cout << "TEST 4 - ARRIVO SUL MURO\n" << endl;
    std::vector<int> Costsmap =
            {0, 1, 9, 6, 7,
             0, 3, 9, 0, 1,
             9, 6, 0, 0, 3,
             4, 6, 9, 0, 3,
             9, 6, 9, 0, 9};  // Fine su un muro
    Map world(5, 5, Costsmap);
    Tile& start = world.getTiles()[0];
    Tile& end = world.getTiles()[24];  // Fine su un muro
    std::vector<Tile*> path = astar(start, end, world);
    ASSERT_TRUE(path.empty());  // Non ci deve essere alcun percorso valido
    cout << "---------------------------------------\n\n";
}

// Test per muro a metà percorso
TEST(AStarTest, WallInMiddle) {
    cout << "TEST 5 - PERCORSO BLOCCATO\n" << endl;
    std::vector<int> Costsmap =
            {0, 1, 9, 6, 7,
             0, 3, 9, 0, 1,
             9, 6, 9, 0, 3,  // Muro a metà
             4, 6, 9, 0, 3,
             9, 6, 9, 0, 0};
    Map world(5, 5, Costsmap);
    Tile& start = world.getTiles()[0];
    Tile& end = world.getTiles()[24];
    std::vector<Tile*> path = astar(start, end, world);
    ASSERT_TRUE(path.empty());  // Non ci deve essere alcun percorso valido
    cout << "---------------------------------------\n\n";
}

// Main per eseguire i test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
