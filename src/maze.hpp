/*
    John "Jack" Riales, J00515647
    CSC-230 Lab 4: Mouse Maze
    Maze Header File
*/

#ifndef MAZE_HPP
#define MAZE_HPP

#include "mouse.hpp"
#include <iostream>
#include <fstream>

class Maze {
public:
    Maze();
    Maze(std::ifstream& in);
    ~Maze();

    void read(std::ifstream& in);
    void print();
    int update();

private:
    static const unsigned int x_max = 5;
    static const unsigned int y_max = 5;
    Tile    _map[x_max][y_max]; // 20x20 map of tiles
    Tile    *_start;            // Pointer to starting position
    Tile    *_cheese;           // Pointer to end (cheese) position
    Mouse   _mouse;             // Mouse that moves through the maze
};

#endif
