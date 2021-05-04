// Author: Braden Wolf
// Description: header file for creature class
// Date: 5/3/21

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

class Creature {
public:
  // prints current location of creature
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
  int Row;
  int Col;

public:
  // constructor
  Creature(int Row, int Col);

  // returns a string in the form of NNEEN of the path out of the maze
  // (where N means North, E means East, etc)
  string solve(Maze *Maze);

  // checks if creature is at the exit
  bool atExit(const Maze &Maze) const;

  // moves creature north
  void goNorth();

  // moves creature south
  void goSouth();

  // moves creature west
  void goWest();

  // moves creature east
  void goEast();
};

#endif //ASS3_CREATURE_H
