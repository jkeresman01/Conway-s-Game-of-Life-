#pragma once

namespace gc
{
    namespace cell
    {
        constexpr float WIDTH = 10.0f; 
        constexpr float HEIGHT = 10.0f; 

        constexpr float ORIGIN_X = WIDTH / 2;
        constexpr float  ORIGIN_Y = HEIGHT / 2;

        constexpr float START_POSITION_X = 45.0f; 
        constexpr float START_POSITION_Y = 100.0f; 

        constexpr float BORDER_THICKNESS = 0.5f; 

        constexpr int NUMBER_OF_NEIGHBOURS = 8;

        enum State
        {
            DEAD = 0,
            ALIVE = 1,
        };
    }

    namespace map
    {
        constexpr int ROWS = 60; 
        constexpr int COLUMNS = 120; 

        constexpr int CRITERIA_ALL_DEAD_CELLS = 0;
        constexpr int CRITERIA_20_PERCENT_ALIVE_CELLS = 20;
    }

    namespace screen
    {
        constexpr int WIDTH = 1280; 
        constexpr int HEIGHT = 720; 

        constexpr int POSITION_X  = 300; 
        constexpr int POSITION_Y  = 200; 
    }

    namespace game
    {
        constexpr float REFRESH_TIME_SECONDS = 2.0f;
        constexpr int FRAMES_PER_SECOND = 60;

        constexpr int UNDERPOPULATION_CRITERIA = 2;
        constexpr int OVERPOPULATION_CRITERIA = 3;

        constexpr int BORN_CRITERIA = 3;

        enum State
        {
            PAUSED = 0,
            RUNNING = 1,
            RESHUFFLED = 2,
        };
    }

    namespace background
    {
        constexpr float SCALE_X = 0.3f;
        constexpr float SCALE_Y = 0.3f;
    }

    namespace title
    {
        constexpr int POSITION_X = 50;
        constexpr int POSITION_Y = 10;

        constexpr int FONT_SIZE = 66;
    }

    namespace button
    {
        constexpr int POSITION_X = screen::WIDTH - 20;
        constexpr int POSITION_Y = 40;

        constexpr float SCALE = 1.2f;
    }
}
