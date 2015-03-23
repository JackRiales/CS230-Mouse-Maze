/*
    John "Jack" Riales, J00515647
    CSC-230 Lab 4: Mouse Maze
    Mouse Header File
*/

#ifndef MOUSE_HPP
#define MOUSE_HPP

#include "tile.hpp"
#include <stack>

class Mouse {
public:
    Mouse (Tile *start);

    void place_at (Tile *tile);
    bool update();

    // Accessors
    inline Tile* current() { return _current; }
    inline bool is_done() { return _done; }

private:
    std::stack<Tile>    _visited;   // Stack of the tiles the mouse has been too
    Tile                *_current;  // Current tile position of the mouse
    bool                _done;      // Is the mouse done searching (running flag)
};

#endif
