/**
 * @file main.cpp
 * @Author Braden Wolf
 * @brief main driver and tests for maze and creature problem
 */

#include <cassert>
#include <iostream>
#include <sstream>

#include "creature.h"
#include "maze.h"



/**
 * Test 1 tests the creature solving a maze using maze.txt
 *
 * Maze object is created and maze.txt is used to initialize the object.
 * Creature object is created and it starts at (4,4). Creature is told to solve
 * maze. Assert is used to check that creature took the correct path to exit.
 *
 * @pre maze and creature classes must be created before this function is used
 * @post maze is solved and marked up with path ('*') and visited ('+') signs
 *       and printed to console
 * @return void
 */
void test1() {
  Maze M("maze.txt");
  Maze *PtrMaze = &M;
  Creature C(4, 4);
  cout << "Creature starting location: " << C << endl;
  cout << "Path: ";
  string s;
  s = C.solve(PtrMaze);
  assert(s == "EEENNNEEEEEESEESSSEEENNNNN");
  cout << s << endl;
  cout << M << endl;
  cout << "Test 1 passed." << endl << endl << endl;
}



/**
 * Test 2 tests the creature solving a maze using maze1.txt
 *
 * Maze object is created and maze1.txt is used to initialize the object.
 * Creature object is created and it starts at (4,4). Creature is told to solve
 * maze. Assert is used to check that creature took the correct path to exit.
 *
 * @pre maze and creature classes must be created before this function is used
 * @post maze1 is solved and marked up with path ('*') and visited ('+') signs
 *       and printed to console
 * @return void
 */
void test2() {
  Maze M("maze1.txt");
  Maze *PtrMaze = &M;
  Creature C(4, 4);
  cout << "Creature starting location: " << C << endl;
  cout << "Path: ";
  string s;
  s = C.solve(PtrMaze);
  assert(s == "NWWWSW");
  cout << s << endl;
  cout << M << endl;
  cout << "Test 2 passed." << endl << endl << endl;
}



/**
 * Test 3 tests the creature solving a maze using maze2.txt
 *
 * Maze object is created and maze2.txt is used to initialize the object.
 * Creature object is created and it starts at (4,4). Creature is told to solve
 * maze. Assert is used to check that creature took the correct path to exit.
 *
 * @pre maze and creature classes must be created before this function is used
 * @post maze2 is solved and marked up with path ('*') and visited ('+') signs
 *       and printed to console
 * @return void
 */
void test3() {
  Maze M("maze2.txt");
  Maze *PtrMaze = &M;
  Creature C(4, 4);
  cout << "Creature starting location: " << C << endl;
  cout << "Path: ";
  string s;
  s = C.solve(PtrMaze);
  assert(s == "NEEEEEEEEESSSSEESEEEEEEEEEEEEEEEEEEEEEEEENEEEEEENEEEEEEEESESEEEE"
              "EEEEEEEEEEEEEEEEEEEENNWWWNNNWWWWWWWWWWWWWWNWWWWWWWWWWWWWWWWWWWWW"
              "WWWNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
  cout << s << endl;
  cout << M << endl;
  cout << "Test 3 passed." << endl << endl << endl;
}



/**
 * Test 4 tests the creature solving a maze using maze3.txt
 *
 * Maze object is created and maze3.txt is used to initialize the object.
 * Creature object is created and it starts at (4,4). Creature is told to solve
 * maze. Assert is used to check that creature took the correct path to exit.
 *
 * @pre maze and creature classes must be created before this function is used
 * @post maze3 is solved and marked up with path ('*') and visited ('+') signs
 *       and printed to console
 * @return void
 */
void test4() {
  Maze M("maze3.txt");
  Maze *PtrMaze = &M;
  Creature C(4, 4);
  cout << "Creature starting location: " << C << endl;
  cout << "Path: ";
  string s;
  s = C.solve(PtrMaze);
  assert(s == "NNNWWWSSSSSSSSSEEESSSSSSSWSSESSWWSWSSESSSSWW");
  cout << s << endl;
  cout << M << endl;
  cout << "Test 4 passed." << endl << endl << endl;
}



/**
 * main driver for maze and creature problem
 *
 * calls tests and prints "Done!"
 *
 * @pre maze and creature classes must be created before this function is used
 * @post maze, maze1, maze2, and maze3 are all solved, mared up and printed to
 *       console. All tests are passed.
 * @return 0
 */
int main() {
  test1();
  test2();
  test3();
  test4();
  cout << "Done!" << std::endl;
  return 0;
}
