#include "headers/Map.h"
#include "headers/GameConstants.h"

Map::Map(sf::RenderWindow* window){
   this->window = window; 
   for(int i = 0; i < GK::MAP::ROWS; ++i){
       for(int j = 0; j < GK::MAP::COLUMNS; ++j){
           cells[i][j] = Cell(window);
           cells[i][j].set_position(
                  GK::CELL::START_POSITION_X + (j* GK::CELL::WIDTH), 
                  GK::CELL::START_POSITION_Y + (i * GK::CELL::HEIGHT));
       }
   }
}

void Map::draw(){
   for(int i = 0; i < GK::MAP::ROWS; ++i){
       for(int j = 0; j < GK::MAP::COLUMNS; ++j){
           cells[i][j].draw();
      }
   }
}
