#include <gtest/gtest.h>

#include "../src/headers/Map.h"

using namespace gol;

class MapTest : public ::testing::Test
{
  protected:
    Map map;
};

TEST_F(MapTest, AfterMapUpdate_WillCellStayDeadIfAllNeighborsAreDead)
{
    map.update();

    Cell *cell = map.getCellAtPosition_NextGeneration(0, 0);
    EXPECT_EQ(cell->isAlive(), false);
}

TEST_F(MapTest, AfterMapUpdate_WillCellStayAliveWithTwoAliveNeighbours)
{
    Cell *cell = map.getCellAtPosition_CurrentGeneration(2, 2);
    cell->setState(State::ALIVE);

    Cell *firstNeighbour = map.getCellAtPosition_CurrentGeneration(2, 3);
    firstNeighbour->setState(State::ALIVE);

    Cell *secondNeighbour = map.getCellAtPosition_CurrentGeneration(3, 2);
    secondNeighbour->setState(State::ALIVE);

    map.update();

    Cell *cellNextGeneration = map.getCellAtPosition_NextGeneration(2, 2);
    EXPECT_EQ(cellNextGeneration->isAlive(), true);
}

TEST_F(MapTest, AfterMapUpdate_WillCellWithThreeAliveNeighboursStayAlive)
{
    Cell *cell = map.getCellAtPosition_CurrentGeneration(2, 2);
    cell->setState(State::ALIVE);

    Cell *firstNeighbour = map.getCellAtPosition_CurrentGeneration(2, 3);
    firstNeighbour->setState(State::ALIVE);

    Cell *secondNeighbour = map.getCellAtPosition_CurrentGeneration(3, 2);
    secondNeighbour->setState(State::ALIVE);

    Cell *thirdNeighbour = map.getCellAtPosition_CurrentGeneration(3, 3);
    thirdNeighbour->setState(State::ALIVE);

    map.update();

    Cell *cellNextGeneration = map.getCellAtPosition_NextGeneration(2, 2);
    EXPECT_EQ(cellNextGeneration->isAlive(), true);
}

TEST_F(MapTest, AfterMapUpdate_WillCellWithOneAliveNeighbourDieOfUnderpopulation)
{
    Cell *cell = map.getCellAtPosition_CurrentGeneration(2, 2);
    cell->setState(State::ALIVE);

    Cell *neighbour = map.getCellAtPosition_CurrentGeneration(2, 3);
    neighbour->setState(State::ALIVE);

    map.update();

    Cell *cellInNextGeneration = map.getCellAtPosition_NextGeneration(2, 2);
    EXPECT_EQ(cellInNextGeneration->isAlive(), false);
}

TEST_F(MapTest, AfterMapUpdate_WillCellWithNoAliveNeighboursDieOfUnderpopulation)
{
    Cell *cell = map.getCellAtPosition_CurrentGeneration(2, 2);
    cell->setState(State::ALIVE);

    map.update();

    Cell *cellNextGeneration = map.getCellAtPosition_NextGeneration(2, 2);
    EXPECT_EQ(cellNextGeneration->isAlive(), false);
}

TEST_F(MapTest, AfterMapUpdate_WillCellWithFourAliveNeighboursDieOfOverpoulation)
{
    Cell *cell = map.getCellAtPosition_CurrentGeneration(2, 2);
    cell->setState(State::ALIVE);

    Cell *firstNeighbour = map.getCellAtPosition_CurrentGeneration(2, 3);
    firstNeighbour->setState(State::ALIVE);

    Cell *secondNeighbour = map.getCellAtPosition_CurrentGeneration(3, 2);
    secondNeighbour->setState(State::ALIVE);

    Cell *thirdNeighbour = map.getCellAtPosition_CurrentGeneration(3, 3);
    thirdNeighbour->setState(State::ALIVE);

    Cell *fourthNeighbour = map.getCellAtPosition_CurrentGeneration(1, 1);
    fourthNeighbour->setState(State::ALIVE);

    map.update();

    Cell *cellInNextGeneration = map.getCellAtPosition_NextGeneration(2, 2);
    EXPECT_EQ(cellInNextGeneration->isAlive(), false);
}

TEST_F(MapTest, AfterMapUpdate_WillDeadCellWithThreeAliveNeighboursBeBorn)
{
    Cell *cell = map.getCellAtPosition_CurrentGeneration(2, 2);
    cell->setState(State::DEAD);

    Cell *firstNeighbour = map.getCellAtPosition_CurrentGeneration(2, 3);
    firstNeighbour->setState(State::ALIVE);

    Cell *secondNeighbour = map.getCellAtPosition_CurrentGeneration(3, 2);
    secondNeighbour->setState(State::ALIVE);

    Cell *thirdNeighbour = map.getCellAtPosition_CurrentGeneration(3, 3);
    thirdNeighbour->setState(State::ALIVE);

    map.update();

    Cell *cellInNextGeneration = map.getCellAtPosition_NextGeneration(2, 2);
    EXPECT_EQ(cellInNextGeneration->isAlive(), true);
}
