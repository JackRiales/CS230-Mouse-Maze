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
    inline void set_done (bool done) { _done = done; }
    inline void set_direction (int dir) { _chosen_dir = dir; }

    // Accessors
    inline Tile lastVisited() { return _visited.top(); }
    inline Tile* current() { return _current; }
    inline bool is_done() { return _done; }
    inline int chosen_dir() { return _chosen_dir; }

    // Direction enum so I dont get confused
    enum DIR {
        UP  = 0,
        DOWN= 1,
        LEFT= 2,
        RIGHT=3
    };

private:
    std::stack<Tile>    _visited;   // Stack of the tiles the mouse has been too
    Tile                *_current;  // Current tile position of the mouse
    bool                _done;      // Is the mouse done searching (running flag)
    int                 _chosen_dir;// Direction mouse is currently going
};

#endif
