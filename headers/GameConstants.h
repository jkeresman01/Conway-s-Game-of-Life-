#pragma once

namespace GK{

    namespace CELL{
        
        constexpr int WIDTH = 10; 
        constexpr int HEIGHT = 10; 

        constexpr int ORIGIN_X = WIDTH / 2;
        constexpr int ORIGIN_Y = HEIGHT / 2;

        enum CellState{
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
