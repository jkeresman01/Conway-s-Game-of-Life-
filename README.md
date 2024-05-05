# Conway's game of Life! #

The Game of Life, also known simply as Life, is a cellular automation devised by the British mathematician John Horton Conway in 1970.
It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.
In this particular instance initial configuration is generated randomly, each cell has a 20% chance to be alive and 80% chance to be dead.

## Rules ##
At each step in time (in this case evey 2s), the following transitions occur:

* Any live cell with fewer than two live neighbors dies, as if by underpopulation.
* Any live cell with two or three live neighbors lives on to the next generation.
* Any live cell with more than three live neighbors dies, as if by overpopulation.
* Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

![game_of_life](https://github.com/jkeresman01/Conway-s-Game-of-Life-/assets/165517653/2c440f9c-2499-47a7-8616-d9e07f34d4b2)
