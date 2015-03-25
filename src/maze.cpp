/*
    John "Jack" Riales, J00515647
    CSC-230 Lab 4: Mouse Maze
    Maze Implementation File
*/

#include "maze.hpp"
using namespace std;

Maze::Maze():
_start(&_map[0][0]),
_cheese(&_map[0][0]),
_mouse(_start),
_initialized(false)
{
    // Seed random for direction choosing
    srand (time(NULL));

    // Iterate through map and initialize tiles
    for (unsigned int x = 0; x < x_max; x++) {
        for (unsigned int y = 0; y < y_max; y++) {
            _map[y][x].x = x;
            _map[y][x].y = y;
            _map[y][x].wall = false;
        }
    }
}

Maze::Maze(std::ifstream& in): Maze()
{
    if (read(in));
        _initialized = true;
}

Maze::~Maze()
{
    /*
    --Caused crash--
    delete _start;
    delete _cheese;
    _start = NULL;
    _cheese = NULL;
    */
}

bool Maze::read(ifstream& in)
{
    if (in.is_open()) {
        char c;
        unsigned int x, y;
        x = y = 0;
        if (x > x_max) {
            cout << "X exceeds x limit. Breaking. Read Failed.\n";
            return false;
        }
        if (y > y_max) {
            cout << "Y exceeds y limit. Breaking. Read Failed.\n";
            return false;
        }
        while (in.get(c)) {
            switch (c) {
            case 's':
                _start = &_map[y][x];
                y++;
                break;
            case 'c':
                _cheese = &_map[y][x];
                y++;
                break;
            case 'w':
                _map[y][x].wall = true;
                y++;
                break;
            case '\n':
                x += 1;
                y = 0;
                break;
            default:
                y++;
            }
        }
    } else {
        cout << "Could not read\n";
    }
    _mouse.place_at( _start );
    return true;
}

void Maze::print()
{
    if (_initialized) {
        for (unsigned int x = 0; x < x_max; x++) {
            for (unsigned int y = 0; y < y_max; y++) {
                if (_mouse.current() == &_map[y][x])
                    cout << "@\t";
                else if (_start == &_map[y][x])
                    cout << "s\t";
                else if (_cheese == &_map[y][x])
                    cout << "c\t";
                else if (_map[y][x].wall)
                    cout << "#\t";
                else
                    cout << " \t";
            }
            cout << "\n\n\n\n";
        }
    } else {
        cout << "Maze not initialized. Cannot print.\n";
        return;
    }
}

int Maze::update()
{
    while (!_mouse.is_done()) {
        // If the mouse is on the cheese, it's done
        if (_mouse.current() == _cheese)
            _mouse.set_done(true);
        else {
            // For reference, where the mouse is right now
            int x = _mouse.current()->x;
            int y = _mouse.current()->y;

            // If no direction has yet been chosen, choose one
            if (_mouse.chosen_dir() == -1) {
                // Otherwise, it needs to pick a direction and go towards it --
                // -- Array of four directions
                bool dirs[] = { false, false, false, false };

                // Check free directions
                if ( y - 1 >= 0 && !_map[y-1][x].wall )
                    dirs[Mouse::UP] = true;
                if ( y + 1 >= 0 && !_map[y+1][x].wall )
                    dirs[Mouse::DOWN] = true;
                if ( x - 1 >= 0 && !_map[y][x-1].wall )
                    dirs[Mouse::LEFT] = true;
                if ( y + 1 >= 0 && !_map[y][x+1].wall )
                    dirs[Mouse::RIGHT] = true;

                bool got_dir = false;
                while (!got_dir) {
                    int random_val = rand()%4;
                    if (dirs[random_val]) {
                        _mouse.set_direction(dirs[random_val]);
                        got_dir = true;
                        cout << got_dir;
                        return 0;
                    }
                }
            }

            // Otherwise, keep moving in that direction until forced to turn
            else {

            }
        }
        print();
    }
    return 0;
}

int main()
{
    ifstream in("input.txt");
    Maze maze (in);
    maze.update();
    return 0;
}
