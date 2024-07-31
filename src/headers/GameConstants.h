#pragma once

#include <SFML/Graphics/Color.hpp>

#include <cstdint>

namespace gol
{

namespace cell
{

constexpr float WIDTH = 10.0f;
constexpr float HEIGHT = 10.0f;

constexpr float ORIGIN_X = WIDTH / 2;
constexpr float ORIGIN_Y = HEIGHT / 2;

constexpr float START_POSITION_X = 45.0f;
constexpr float START_POSITION_Y = 100.0f;

constexpr float OUTLINE_THICKNESS = 0.5f;

constexpr uint32_t NUMBER_OF_NEIGHBOURS = 8;

enum State : uint8_t
{
    DEAD = 0,
    ALIVE = 1,
};

namespace Colors
{
const sf::Color DEAD = sf::Color(250, 191, 106, 10);
const sf::Color ALIVE = sf::Color(250, 191, 106, 180);
} // namespace Colors
} // namespace cell

namespace map
{
constexpr uint32_t ROWS = 60;
constexpr uint32_t COLUMNS = 120;

enum Critera : uint8_t
{
    ALL_DEAD = 0,
    RANDOM = 20,
    ALL_ALIVE = 100,
};
} // namespace map

namespace screen
{
constexpr uint32_t WIDTH = 1280;
constexpr uint32_t HEIGHT = 720;

constexpr uint32_t POSITION_X = 300;
constexpr uint32_t POSITION_Y = 200;
} // namespace screen

namespace game
{
constexpr float REFRESH_TIME_SECONDS = 2.0f;

constexpr uint32_t FRAMES_PER_SECOND = 60;

enum Criteria : uint8_t
{
    UNDERPOPULATION = 2,
    BORN = 3,
    OVERPOPULATION = 4,
};

enum State : uint8_t
{
    PAUSED = 0,
    RUNNING = 1,
    RESHUFFLED = 2,
};
} // namespace game

namespace background
{
constexpr float SCALE_X = 0.3f;
constexpr float SCALE_Y = 0.3f;
} // namespace background

namespace title
{
constexpr uint32_t POSITION_X = 50;
constexpr uint32_t POSITION_Y = 10;

constexpr uint32_t FONT_SIZE = 66;
} // namespace title

namespace button
{
constexpr uint32_t POSITION_X = screen::WIDTH - 20;
constexpr uint32_t POSITION_Y = 40;

constexpr float INCREASE_FACTOR = 1.1f;
constexpr float SCALE = 1.2f;
} // namespace button

} // namespace gol
