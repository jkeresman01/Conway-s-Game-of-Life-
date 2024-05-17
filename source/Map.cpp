#include "headers/Map.h"
#include "headers/Cell.h"
#include "headers/GameConstants.h"
#include <algorithm>

Map::Map(){}

Map::Map(sf::RenderWindow* window){
    this->window = window;
    display_loading_screen();
}

void Map::create(sf::RenderWindow* window){
    this->window = window;
    display_loading_screen();
}

void Map::display_loading_screen(){
    initilize_cells(gc::MAP::CRITERIA_ALL_DEAD_CELLS);
    lets_call_this_thing_sun();
    lets_throw_some_stars_arround();
}

void Map::update(){
    for(int i = 0; i < gc::MAP::ROWS; ++i){
        for(int j = 0; j < gc::MAP::COLUMNS; ++j){
            if(!is_border(i, j)){
                change_for_next_generation(current_generation[i][j], i, j);
            }
        }
    }

    for(int i = 0; i < gc::MAP::ROWS; ++i){
        for(int j = 0; j < gc::MAP::COLUMNS; ++j){
            if(!is_border(i, j)){
                current_generation[i][j] = next_generation[i][j];
            }
        }
    }
}

void Map::draw(){
    for(int i = 0; i < gc::MAP::ROWS; ++i){
        for(int j = 0; j < gc::MAP::COLUMNS; ++j){
            if(!is_border(i, j)){
                current_generation[i][j].draw();
            }
        }
    }
}

void Map::initilize_cells(int criteria_for_alive){
    for(int i = 0; i < gc::MAP::ROWS; ++i){
        for(int j = 0; j < gc::MAP::COLUMNS; ++j){
            current_generation[i][j].set_window(window);
            current_generation[i][j].set_position(
                    gc::CELL::START_POSITION_X + (j * gc::CELL::WIDTH), 
                    gc::CELL::START_POSITION_Y + (i * gc::CELL::HEIGHT));
            if(!is_border(i, j)){
                current_generation[i][j].set_state(get_random_cell_state(criteria_for_alive));
            }
            next_generation[i][j] = current_generation[i][j];
       }
   }
}

bool Map::is_border(int i, int j){
    return i == 0 or i == gc::MAP::ROWS - 1 or j == 0 or j == gc::MAP::COLUMNS -1;
}

int Map::generate_number(int max, int min){
    return rand() % (max - min + 1) + min;
}

gc::CELL::STATE Map::get_random_cell_state(int criteria_for_alive){
    return generate_number(100, 1) <= criteria_for_alive
                    ? gc::CELL::STATE::ALIVE
                    : gc::CELL::STATE::DEAD;
}

void Map::change_for_next_generation(Cell &cell, int postition_x, int position_y){

    Cell Neighbours[gc::CELL::NUMBER_OF_NEIGHBOURS]{
        current_generation[postition_x - 1][position_y],
        current_generation[postition_x + 1][position_y],
        current_generation[postition_x][position_y - 1],
        current_generation[postition_x][position_y + 1],
        current_generation[postition_x - 1][position_y - 1],
        current_generation[postition_x + 1][position_y + 1],
        current_generation[postition_x + 1][position_y - 1],
        current_generation[postition_x - 1][position_y + 1],
    };

    int alive_nieghbours = std::count_if(Neighbours, Neighbours + gc::CELL::NUMBER_OF_NEIGHBOURS,
                            [](Cell &cell){ return cell.is_alive();});

    if(cell.is_alive() and alive_nieghbours > 3 or alive_nieghbours < 2){
        next_generation[postition_x][position_y].set_state(gc::CELL::DEAD);
    }

    if(!cell.is_alive() and alive_nieghbours == 3){
        next_generation[postition_x][position_y].set_state(gc::CELL::ALIVE);
    }
}

void Map::lets_throw_some_stars_arround(){
    draw_something_like_a_star(4, 520);
    draw_something_like_a_star(2, 270);
    draw_something_like_a_star(4, 100);
}

void Map::draw_something_like_a_star(int offset_x, int offset_y){
    for(int i = 0; i < gc::STAR::WIDTH; ++i){
        for(int j = 0; j < gc::STAR::HEIGHT; ++j){
            if(!(i == 1 and j == 1)){
                next_generation[offset_x + i] [offset_y + j].set_state(gc::CELL::STATE::ALIVE);
            }
            current_generation[offset_x + i] [offset_y + j] = next_generation[offset_x + i] [offset_y + j];
        }
    }
}

void Map::lets_call_this_thing_sun(){
    draw_first_quadrant();
    draw_second_quadrant();
    draw_third_quadrant();
    draw_fourth_quadrant();
}

void Map::draw_first_quadrant(){
    for(int i = 0; i < gc::SUN::QUADRANT_WIDTH; i++){
        for(int j = 0; j < gc::SUN::QUADRANT_WIDTH; j++){
            if((i == gc::SUN::QUADRANT_WIDTH - 1 or j == gc::SUN::QUADRANT_WIDTH - 1) 
                or (i == gc::SUN::QUADRANT_WIDTH - 2 and j == gc::SUN::QUADRANT_WIDTH - 2)){
                if(i == gc::SUN::QUADRANT_WIDTH - 1 and j == gc::SUN::QUADRANT_WIDTH - 1){
                    next_generation[gc::SUN::OFFSET_X + i] 
                                   [gc::SUN::OFFSET_Y + j]
                                   .set_state(gc::CELL::STATE::DEAD);
                }else {
                    next_generation[gc::SUN::OFFSET_X + i] 
                                   [gc::SUN::OFFSET_Y + j]
                                   .set_state(gc::CELL::STATE::ALIVE);
                }
            }else{
                next_generation[gc::SUN::OFFSET_X + i] 
                               [gc::SUN::OFFSET_Y + j]
                               .set_state(gc::CELL::STATE::DEAD);
            }
            current_generation[gc::SUN::OFFSET_X + i] [gc::SUN::OFFSET_Y + j]
            = next_generation[gc::SUN::OFFSET_X + i] [gc::SUN::OFFSET_Y + j];
        }
    }
}

void Map::draw_second_quadrant(){
    for(int i = 0; i < gc::SUN::QUADRANT_WIDTH; i++){
        for(int j = 0; j < gc::SUN::QUADRANT_WIDTH; j++){
            if((j == 0 or i == gc::SUN::QUADRANT_WIDTH - 1) or (j == 1 and i == gc::SUN::QUADRANT_WIDTH - 2)){
                if(i == gc::SUN::QUADRANT_WIDTH - 1 and j == 0){
                  next_generation[gc::SUN::OFFSET_X + i] 
                                 [gc::SUN::OFFSET_Y + gc::SUN::QUADRANT_WIDTH  + gc::SUN::DEAD_SPACE + j]
                                 .set_state(gc::CELL::STATE::DEAD);
                }else {
                  next_generation[gc::SUN::OFFSET_X + i] 
                                 [gc::SUN::OFFSET_Y + gc::SUN::QUADRANT_WIDTH  + gc::SUN::DEAD_SPACE + j]
                                 .set_state(gc::CELL::STATE::ALIVE);
                }
            }else{
                  next_generation[gc::SUN::OFFSET_X + i] 
                                 [gc::SUN::OFFSET_Y + gc::SUN::QUADRANT_WIDTH  + gc::SUN::DEAD_SPACE + j]
                                 .set_state(gc::CELL::STATE::DEAD);
            }
            current_generation[gc::SUN::OFFSET_X + i] [gc::SUN::OFFSET_Y + gc::SUN::QUADRANT_WIDTH  + gc::SUN::DEAD_SPACE + j]
                = next_generation[gc::SUN::OFFSET_X + i] [gc::SUN::OFFSET_Y + gc::SUN::QUADRANT_WIDTH  + gc::SUN::DEAD_SPACE + j];
        }
    }}

void Map::draw_third_quadrant(){
    for(int i = 0; i < gc::SUN::QUADRANT_WIDTH; i++){
        for(int j = 0; j < gc::SUN::QUADRANT_WIDTH; j++){
            if((i == 0 or j == gc::SUN::QUADRANT_WIDTH - 1) or (i == 1 and j == gc::SUN::QUADRANT_WIDTH - 2)){
                if(i == 0 and j == gc::SUN::QUADRANT_WIDTH - 1){
                    next_generation[gc::SUN::OFFSET_X + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + i] 
                                   [gc::SUN::OFFSET_Y + j]
                                   .set_state(gc::CELL::STATE::DEAD);
                }else {
                    next_generation[gc::SUN::OFFSET_X + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + i] 
                                   [gc::SUN::OFFSET_Y + j]
                                   .set_state(gc::CELL::STATE::ALIVE);
                }
            }else{
                next_generation[gc::SUN::OFFSET_X + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + i]
                               [gc::SUN::OFFSET_Y + j]
                               .set_state(gc::CELL::STATE::DEAD);
            }
            current_generation[gc::SUN::OFFSET_X + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + i] [gc::SUN::OFFSET_Y + j] =
                next_generation[gc::SUN::OFFSET_X + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + i] [gc::SUN::OFFSET_Y + j];
        }
    }
}

void Map::draw_fourth_quadrant(){
    for(int i = 0; i < gc::SUN::QUADRANT_WIDTH; i++){
        for(int j = 0; j < gc::SUN::QUADRANT_WIDTH; j++){
            if((i == 0 or j == 0) or (i == 1 and j == 1)){
                if(i == 0 and j == 0){
                    next_generation[gc::SUN::OFFSET_X + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + i] 
                                   [gc::SUN::OFFSET_Y + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + j]
                                   .set_state(gc::CELL::STATE::DEAD);
                }else {
                    next_generation[gc::SUN::OFFSET_X + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + i] 
                                   [gc::SUN::OFFSET_Y + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + j]
                                   .set_state(gc::CELL::STATE::ALIVE);
                }
            }else{
                next_generation[gc::SUN::OFFSET_X + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + i] 
                               [gc::SUN::OFFSET_Y + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + j]
                               .set_state(gc::CELL::STATE::DEAD);
            }
            current_generation[gc::SUN::OFFSET_X + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + i] 
                              [gc::SUN::OFFSET_Y + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + j] =
            next_generation[gc::SUN::OFFSET_X + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + i] 
                           [gc::SUN::OFFSET_Y + gc::SUN::DEAD_SPACE + gc::SUN::QUADRANT_WIDTH + j];
        }
    }
}

