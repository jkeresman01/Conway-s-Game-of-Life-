#include <SFML/Window/Mouse.hpp>
#include <gtest/gtest.h>

#include "../src/headers/Button.h"

using namespace gol;

class ButtonTest : public ::testing::Test
{
  protected:
    Button button;
};
