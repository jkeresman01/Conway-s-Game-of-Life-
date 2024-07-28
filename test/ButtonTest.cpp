#include <SFML/Window/Mouse.hpp>
#include <gtest/gtest.h>

#include "../src/headers/Button.h"
#include "../src/headers/GameConstants.h"

using namespace gol;

class ButtonTest : public ::testing::Test 
{
protected:
    Button button;
    sf::Mouse mouse;

    void SetUp() override {
        button.create(nullptr, "resources/images/play-button.jpg");
    }
};

TEST_F(ButtonTest, AfterButtonIsCreated_WillPositionBeTopRightCorner) 
{
    EXPECT_EQ(button.getPosition().first, button::POSITION_X);
    EXPECT_EQ(button.getPosition().second, button::POSITION_Y);
}

