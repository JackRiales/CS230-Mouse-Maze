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
_mouse(_start)
{
    // Iterate through map and initialize tiles
    for (unsigned int x = 0; x < x_max; x++) {
        for (unsigned int y = 0; y < y_max; y++) {
            _map[x][y].x = x;
            _map[x][y].y = y;
            _map[x][y].wall = false;
        }
    }
}

Maze::Maze(std::ifstream& in): Maze()
{
    read(in);
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

void Maze::read(ifstream& in)
{
    if (in.is_open()) {
        char c;
        unsigned int x, y;
        x = y = 0;
        while (in.get(c)) {
            switch (c) {
            case 's':
                _start = &_map[x][y];
                break;
            case 'c':
                _cheese = &_map[x][y];
                break;
            case 'w':
                _map[x][y].wall = true;
            }
        }
    } else {
        cout << "Could not read\n";
    }
}

void Maze::print()
{
    for (unsigned int x = 0; x < x_max; x++) {
        for (unsigned int y = 0; y < y_max; y++) {
            if (_mouse.current() == &_map[x][y])
                cout << "@ ";
            else if (_start == &_map[x][y])
                cout << "s ";
            else if (_cheese == &_map[x][y])
                cout << "c ";
            else if (_map[x][y].wall)
                cout << "1 ";
            else
                cout << "8 ";
        }
        cout << endl;
    }
}

int Maze::update()
{
    return 0;
}

int main()
{
    ifstream in("input.txt");
    Maze maze (in);
    maze.print();
    return 0;
}
