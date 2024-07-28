#include <gtest/gtest.h>

#include "../src/headers/Cell.h"
#include "../src/headers/GameConstants.h"

using namespace gol;

class CellTest : public ::testing::Test 
{
protected:
    Cell cell;
};

TEST_F(CellTest, AfterCellIsCreated_WillCellBeDead) 
{
    EXPECT_EQ(cell.isAlive(), false);
}

TEST_F(CellTest, AfterCellIsCreate_WillCellColorBeTransparentDead)
{
    EXPECT_EQ(cell.getColor(), cell::Colors::DEAD);
}

TEST_F(CellTest, AfterCellStateChangesToAlive_WillCellStateBeAlive) 
{
    cell.setState(cell::State::ALIVE);
    EXPECT_EQ(cell.isAlive(), true);
}

TEST_F(CellTest, AfterCellStateChangesToAlive_WillCellColorBeYellowAlive) 
{
    cell.setState(cell::State::ALIVE);
    EXPECT_EQ(cell.getColor(), cell::Colors::ALIVE);
}

