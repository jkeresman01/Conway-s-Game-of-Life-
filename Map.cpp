#include "headers/Map.h"
#include "headers/Cell.h"
#include "headers/GameConstants.h"
#include <algorithm>

Map::Map(sf::RenderWindow* window){
    this->window = window; 
    initilize_cells(20);
}

void Map::draw(){
   for(int i = 0; i < gc::MAP::ROWS; ++i){
       for(int j = 0; j < gc::MAP::COLUMNS; ++j){
           next_generation[i][j].draw();
      }
   }
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

void Map::initilize_cells(int criteria_for_alive){
    Cell cell = Cell(window);
    for(int i = 0; i < gc::MAP::ROWS; ++i){
        for(int j = 0; j < gc::MAP::COLUMNS; ++j){
            current_generation[i][j] = cell;
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
    return i == 0 || i == gc::MAP::ROWS - 1 || j == 0 || j == gc::MAP::COLUMNS -1;
}

int Map::generate_number(int max, int min){
    return rand() % (max - min + 1) + min;
}

gc::CELL::CELL_STATE Map::get_random_cell_state(int criteria_for_alive){
    return generate_number(100, 1) <= criteria_for_alive
                    ? gc::CELL::CELL_STATE::ALIVE
                    : gc::CELL::CELL_STATE::DEAD;
}

void Map::change_for_next_generation(Cell &cell, int postition_x, int position_y){

    Cell neighbours[gc::CELL::NUMBER_OF_NEIGHBOURS]{
        current_generation[postition_x - 1][position_y],
        current_generation[postition_x + 1][position_y],
        current_generation[postition_x][position_y - 1],
        current_generation[postition_x][position_y + 1],
        current_generation[postition_x - 1][position_y - 1],
        current_generation[postition_x + 1][position_y + 1],
        current_generation[postition_x + 1][position_y - 1],
        current_generation[postition_x - 1][position_y + 1],
    };

    int alive_nieghbours = std::count_if(neighbours, neighbours + gc::CELL::NUMBER_OF_NEIGHBOURS,
                            [](Cell &cell){ return cell.is_alive();});

    if(cell.is_alive() && alive_nieghbours > 3 || alive_nieghbours < 2){
        next_generation[postition_x][position_y].set_state(gc::CELL::DEAD);
    }

    if(!cell.is_alive() && alive_nieghbours == 3){
        next_generation[postition_x][position_y].set_state(gc::CELL::ALIVE);
    }
}
