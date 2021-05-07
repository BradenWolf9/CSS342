/**
 * @file creature.h
 * @Author Braden Wolf
 * @brief header file for maze class
 */



#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {
  // prints ASCII display of maze
  friend ostream &operator<<(ostream &Out, const Maze &Maze);

private:
  const static int MAX_SIZE = 100;
  char Field[MAX_SIZE][MAX_SIZE];
  int Width, Height;
  int ExitRow, ExitColumn;

public:
  // constructor
  explicit Maze(const string &FileName);
  // checks if given location has any markers
  bool isClear(int Row, int Col) const;
  // marks given location with a '*'
  void markAsPath(int Row, int Col);
  // marks given location with a '+'
  void markAsVisited(int Row, int Col);
  // returns exit row
  int getExitRow() const;
  // returns exit column
  int getExitColumn() const;

};

#endif //ASS3_MAZE_H
