#pragma once

namespace gc{

    namespace CELL{
        
        constexpr float WIDTH = 10.f; 
        constexpr float HEIGHT = 10.f; 

        constexpr float ORIGIN_X = WIDTH / 2;
        constexpr int ORIGIN_Y = HEIGHT / 2;

        constexpr float START_POSITION_X = 50.f; 
        constexpr float START_POSITION_Y = 95.f; 

        constexpr float BORDER_THICKNESS = 0.5f; 

        constexpr int NUMBER_OF_NEIGHBOURS = 8;

        enum STATE{
            ALIVE = 1,
            DEAD = 0,
        };
    }

    namespace SUN{
        constexpr int OFFSET_Y = 6;
        constexpr int OFFSET_X = 6;

        constexpr int DEAD_SPACE = 2;
        constexpr int QUADRANT_WIDTH = 4;

    }

    namespace MAP{
        constexpr int ROWS = 60; 
        constexpr int COLUMNS = 115; 
    }

    namespace SCREEN{
        constexpr int WIDTH = 1280; 
        constexpr int COLUMNS = 720; 
    }

    namespace GAME{
        enum STATE{
            PAUSED = 0,
            RUNNING = 1,
            RESTARTED = 2,
        };
    }

}
