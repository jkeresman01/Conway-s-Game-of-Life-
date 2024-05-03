#pragma once
#include "Cell.h"
#include "GameConstants.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Map{
    private:
        sf::RenderWindow* window;
        Cell current_generation [gc::MAP::ROWS][gc::MAP::COLUMNS];
        Cell next_generation [gc::MAP::ROWS][gc::MAP::COLUMNS];

    private:
        int generate_number(int max, int min);
        gc::CELL::CELL_STATE get_random_cell_state(int criteria_for_alive);
        bool is_border(int i, int j);
        void change_for_next_generation(Cell &cell, int postion_x, int positon_y);

    public:
        Map(sf::RenderWindow* window);
        void initilize_cells(int criteria_for_alive);
        void draw();
        void update();
};
