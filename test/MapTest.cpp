#include <gtest/gtest.h>

#include "../src/headers/GameConstants.h"
#include "../src/headers/Map.h"

using namespace gol;

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

class MapTest : public ::testing::Test
{
  protected:
    Map map;

    void SetUp() override
    {
        map.create(nullptr);
    }
};

TEST_F(MapTest, AfterMapIsCreated_WillCellsBeDeadInCurrentGeneration)
{
    for (size_t i = 0; i < map::ROWS; ++i)
    {
        for (size_t j = 0; j < map::COLUMNS; ++j)
        {
            Cell *cell = map.getCellAtPosition_CurrentGeneration(i, j);
            EXPECT_EQ(cell->isAlive(), false);
        }
    }
}

TEST_F(MapTest, AfterMapIsCreated_WillCellsBeDeadInNextGeneration)
{
    for (size_t i = 0; i < map::ROWS; ++i)
    {
        for (size_t j = 0; j < map::COLUMNS; ++j)
        {
            Cell *cell = map.getCellAtPosition_NextGeneration(i, j);
            EXPECT_EQ(cell->isAlive(), false);
        }
    }
}

TEST_F(MapTest, AfterMapUpdate_WillCellStayDeadIfAllNeighborsAreDead)
{
    map.update();

    Cell *cell = map.getCellAtPosition_NextGeneration(0, 0);
    EXPECT_EQ(cell->isAlive(), false);
}

TEST_F(MapTest, AfterMapUpdate_WillCellStayAliveWithTwoAliveNeighbours)
{
    Cell *cell = map.getCellAtPosition_CurrentGeneration(2, 2);
    cell->setState(cell::State::ALIVE);

    Cell *firstNeighbour = map.getCellAtPosition_CurrentGeneration(2, 3);
    firstNeighbour->setState(cell::State::ALIVE);

    Cell *secondNeighbour = map.getCellAtPosition_CurrentGeneration(3, 2);
    secondNeighbour->setState(cell::State::ALIVE);

    map.update();

    Cell *cellNextGeneration = map.getCellAtPosition_NextGeneration(2, 2);
    EXPECT_EQ(cell->isAlive(), true);
}

TEST_F(MapTest, AfterMapUpdate_WillCellWithThreeAliveNeighboursStayAlive)
{
    Cell *cell = map.getCellAtPosition_CurrentGeneration(2, 2);
    cell->setState(cell::State::ALIVE);

    Cell *firstNeighbour = map.getCellAtPosition_CurrentGeneration(2, 3);
    firstNeighbour->setState(cell::State::ALIVE);

    Cell *secondNeighbour = map.getCellAtPosition_CurrentGeneration(3, 2);
    secondNeighbour->setState(cell::State::ALIVE);

    Cell *thirdNeighbour = map.getCellAtPosition_CurrentGeneration(3, 3);
    thirdNeighbour->setState(cell::State::ALIVE);

    map.update();

    Cell *cellNextGeneration = map.getCellAtPosition_NextGeneration(2, 2);
    EXPECT_EQ(cellNextGeneration->isAlive(), true);
}

TEST_F(MapTest,
       AfterMapUpdate_WillCellWithOneAliveNeighbourDieOfUnderpopulation)
{
    Cell *cell = map.getCellAtPosition_CurrentGeneration(2, 2);
    cell->setState(cell::State::ALIVE);

    Cell *neighbour = map.getCellAtPosition_CurrentGeneration(2, 3);
    neighbour->setState(cell::State::ALIVE);

    map.update();

    Cell *cellInNextGeneration = map.getCellAtPosition_NextGeneration(2, 2);
    EXPECT_EQ(cellInNextGeneration->isAlive(), false);
}

TEST_F(MapTest,
       AfterMapUpdate_WillCellWithNoAliveNeighboursDieOfUnderpopulation)
{
    Cell *cell = map.getCellAtPosition_CurrentGeneration(2, 2);
    cell->setState(cell::State::ALIVE);

    map.update();

    Cell *cellNextGeneration = map.getCellAtPosition_NextGeneration(2, 2);
    EXPECT_EQ(cell->isAlive(), false);
}

TEST_F(MapTest,
       AfterMapUpdate_WillCellWithFourAliveNeighboursDieOfOverpoulation)
{
    Cell *cell = map.getCellAtPosition_CurrentGeneration(2, 2);
    cell->setState(cell::State::ALIVE);

    Cell *firstNeighbour = map.getCellAtPosition_CurrentGeneration(2, 3);
    firstNeighbour->setState(cell::State::ALIVE);

    Cell *secondNeighbour = map.getCellAtPosition_CurrentGeneration(3, 2);
    secondNeighbour->setState(cell::State::ALIVE);

    Cell *thirdNeighbour = map.getCellAtPosition_CurrentGeneration(3, 3);
    thirdNeighbour->setState(cell::State::ALIVE);

    Cell *fourthNeighbour = map.getCellAtPosition_CurrentGeneration(1, 1);
    fourthNeighbour->setState(cell::State::ALIVE);

    map.update();

    Cell *cellInNextGeneration = map.getCellAtPosition_NextGeneration(2, 2);
    EXPECT_EQ(cellInNextGeneration->isAlive(), false);
}

TEST_F(MapTest, AfterMapUpdate_WillDeadCellWithThreeAliveNeighboursBeBorn)
{
    Cell *cell = map.getCellAtPosition_CurrentGeneration(2, 2);

    Cell *firstNeighbour = map.getCellAtPosition_CurrentGeneration(2, 3);
    firstNeighbour->setState(cell::State::ALIVE);

    Cell *secondNeighbour = map.getCellAtPosition_CurrentGeneration(3, 2);
    secondNeighbour->setState(cell::State::ALIVE);

    Cell *thirdNeighbour = map.getCellAtPosition_CurrentGeneration(3, 3);
    thirdNeighbour->setState(cell::State::ALIVE);

    map.update();

    Cell *cellInNextGeneration = map.getCellAtPosition_NextGeneration(2, 2);
    EXPECT_EQ(cellInNextGeneration->isAlive(), true);
}
