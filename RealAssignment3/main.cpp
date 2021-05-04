// Author: Braden Wolf
// Description: main driver for maze and creature problem
// Date: 5/3/21

#include <iostream>

#include "creature.h"
#include "maze.h"


void test() {
    Maze M("maze.txt");
    Maze *PtrMaze = &M;
    Creature C(4, 4);
    cout << C << endl;
    cout << "Path: " << C.solve(PtrMaze) << endl;
    cout << M << endl;
}
int main() {
    test();
    cout << "Done!" << std::endl;
    return 0;
}
