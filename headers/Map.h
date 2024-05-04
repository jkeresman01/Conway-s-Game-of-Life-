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
        gc::CELL::STATE get_random_cell_state(int criteria_for_alive);
        bool is_border(int i, int j);
        void change_for_next_generation(Cell &cell, int postion_x, int positon_y);
        void draw_first_quadrant();
        void draw_second_quadrant();
        void draw_third_quadrant();
        void draw_fourth_quadrant();
        void lets_call_this_thing_sun();
        void lets_throw_some_stars_arround();
        void lets_call_this_spaceship();
        void draw_something_like_a_star(int offset_x, int offset_y);

    public:
        Map(sf::RenderWindow* window);
        void initilize_cells(int criteria_for_alive);
        void draw();
        void update();
};
