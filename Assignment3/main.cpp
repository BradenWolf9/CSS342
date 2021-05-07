/**
 * @file creature.h
 * @Author Braden Wolf
 * @brief main driver and tests for maze and creature problem
 */



#include <iostream>

#include "creature.h"
#include "maze.h"


void test() {
    Maze M("maze3.txt");
    Maze *PtrMaze = &M;
    Creature C(4, 4);
    cout << "Creature starting location: " << C << endl;
    cout << "Path: " << C.solve(PtrMaze) << endl;
    cout << M << endl;
}
int main() {
    test();
    cout << "Done!" << std::endl;
    return 0;
}
