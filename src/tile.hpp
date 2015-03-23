/*
    John "Jack" Riales, J00515647
    CSC-230 Lab 4: Mouse Maze
    Tile Header File
*/

#ifndef TILE_HPP
#define TILE_HPP

struct Tile {
    unsigned int x;     // X coordinate of the tile
    unsigned int y;     // Y coordinate of the tile
    bool wall;          // Determines if the tile is a wall or not
};

#endif
