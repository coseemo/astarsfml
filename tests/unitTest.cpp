#include "gtest/gtest.h"
#include "../src/game.h"
#include "../src/astar.h"

// Test per mappa con percorso valido 1
TEST(AStarTest, ValidPath1) {
    cout << "TEST 1 - PERCORSO VALIDO 1\n" << endl;
    std::vector<int> Costsmap =
            {0, 1, 9, 6, 7,
             0, 3, 9, 0, 1,
             9, 6, 0, 0, 3,
             4, 6, 9, 0, 3,
             9, 6, 9, 0, 0};
    Map world(5, 5, Costsmap);
    Tile& start = world.getTiles()[0];
    Tile& end = world.getTiles()[24];
    std::vector<Tile*> path = astar(start, end, world);
    ASSERT_FALSE(path.empty());  // Il percorso non deve essere vuoto
    ASSERT_EQ(path.front(), &start);  // Il percorso deve iniziare dal tile di partenza
    ASSERT_EQ(path.back(), &end);  // Il percorso deve finire al tile di arrivo
    cout << "---------------------------------------\n\n";
}

// Test per mappa con percorso valido 2
TEST(AStarTest, ValidPath2) {
    cout << "TEST 2 - PERCORSO VALIDO 2\n" << endl;
    std::vector<int> Costsmap =
            {4, 1, 9, 6, 7,
             0, 3, 9, 0, 1,
             9, 6, 0, 0, 3,
             4, 6, 9, 0, 3,
             9, 6, 9, 0, 0};
    Map world(5, 5, Costsmap);
    Tile& start = world.getTiles()[0];
    Tile& end = world.getTiles()[24];
    std::vector<Tile*> path = astar(start, end, world);
    ASSERT_FALSE(path.empty());  // Il percorso non deve essere vuoto
    ASSERT_EQ(path.front(), &start);  // Il percorso deve iniziare dal tile di partenza
    ASSERT_EQ(path.back(), &end);  // Il percorso deve finire al tile di arrivo
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
