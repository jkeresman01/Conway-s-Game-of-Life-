#include <gtest/gtest.h>

#include "../src/headers/Map.h"
#include "../src/headers/GameConstants.h"

using namespace gol;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class MapTest : public ::testing::Test {
protected:
    Map map;
    sf::RenderWindow window;

    void SetUp() override {
        map.create(&window);
    }
};

TEST_F(MapTest, AfterMapIsCreated_WillCellsBeDeadInNextGeneration) 
{
    for(size_t i = 0; i < map::ROWS; ++i)
    {
        for(size_t j = 0; j < map::COLUMNS; ++j)
        {
            Cell cell = map.getCellAtPosition_NextGeneration(i, j);
            EXPECT_EQ(cell.isAlive(), false);
        }
    }
}
