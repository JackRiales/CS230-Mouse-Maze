/*
    John "Jack" Riales, J00515647
    CSC-230 Lab 4: Mouse Maze
    Mouse Implementation File
*/

#include "mouse.hpp"
using namespace std;

Mouse::Mouse(Tile *start):
_current(start),
_done(false),
_chosen_dir (-1)
{
    ;
}

void Mouse::place_at(Tile *tile)
{
    _current = tile;
    _visited.push(*tile);
}
