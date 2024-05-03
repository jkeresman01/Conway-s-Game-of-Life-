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

        enum CELL_STATE{
            ALIVE = 1,
            DEAD = 0,
        };
    }

    namespace MAP{
        constexpr int ROWS = 60; 
        constexpr int COLUMNS = 95; 
    }

    namespace SCREEN{
        constexpr int WIDTH = 1280; 
        constexpr int COLUMNS = 720; 

    }

}
