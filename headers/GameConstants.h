#pragma once

namespace gc{

    namespace CELL{
        constexpr float WIDTH = 10.f; 
        constexpr float HEIGHT = 10.f; 

        constexpr float ORIGIN_X = WIDTH / 2;
        constexpr int ORIGIN_Y = HEIGHT / 2;

        constexpr float START_POSITION_X = 45.f; 
        constexpr float START_POSITION_Y = 100.f; 

        constexpr float BORDER_THICKNESS = 0.5f; 

        constexpr int NUMBER_OF_NEIGHBOURS = 8;

        enum STATE{
            ALIVE = 1,
            DEAD = 0,
        };
    }

    namespace SUN{
        constexpr int OFFSET_Y = 4;
        constexpr int OFFSET_X = 4;

        constexpr int DEAD_SPACE = 2;
        constexpr int QUADRANT_WIDTH = 4;
    }

    namespace MAP{
        constexpr int ROWS = 60; 
        constexpr int COLUMNS = 120; 

        constexpr int CRITERIA_ALL_DEAD_CELLS = 0;
        constexpr int CRITERIA_20_PERCENT_ALIVE_CELLS = 20;
    }

    namespace SCREEN{
        constexpr int WIDTH = 1280; 
        constexpr int HEIGHT = 720; 

        constexpr int POSITION_X  = 300; 
        constexpr int POSITION_Y  = 200; 
    }

    namespace GAME{
        constexpr float REFRESH_TIME_SECONDS = 2.0f;
        constexpr int FRAMES_PER_SECOND = 60;

        enum STATE{
            PAUSED = 0,
            RUNNING = 1,
            RESTARTED = 2,
        };
    }

    namespace BACKGROUND{
        constexpr float SCALE_X = 0.3f;
        constexpr float SCALE_Y = 0.3f;
    }

    namespace TITLE{
        constexpr int POSITION_X = 50;
        constexpr int POSITION_Y = 10;
    }

    namespace BUTTON{
        constexpr int POSITION_X = SCREEN::WIDTH - 20;
        constexpr int POSITION_Y = 40;

        constexpr float SCALE_X = 1.2f;
        constexpr float SCALE_Y = 1.2f;
    }

    namespace STAR{
        constexpr int WIDTH = 3;
        constexpr int HEIGHT = 3;
    }

}
