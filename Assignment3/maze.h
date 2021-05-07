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



/**
 * Maze object is what the creature moves through
 *
 * variable Field holds the maze field
 * variable Width holds the width of the field
 * variable Height holds the height of the field
 * variable ExitRow holds the row of the field exit
 * varibale ExitColumn holds the column of the field exit
 */
class Maze {

  /**
   * prints ASCII display of maze
   *
   * uses nested for loop to iterate through 2D array, Field, and fill Out
   *
   * @pre Maze object must be filled with a Field, Height, and Width
   * @post doesn't change any variables
   * @param Out is filled with the Field
   * @param Maze is used to get the Heigth, Width, and Field
   * @return Returns Out
   */
  friend ostream &operator<<(ostream &Out, const Maze &Maze);

private:
  const static int MAX_SIZE = 100;
  char Field[MAX_SIZE][MAX_SIZE];
  int Width, Height;
  int ExitRow, ExitColumn;

public:
  /**
   * constructor
   *
   * First number in file is Width, second is Height, third is ExitRow, fourth
   * is ExitColumn. File also contains Field that is input to a 2D array using
   * a nested for loop.
   *
   * @pre Must have file with proper format to fill the maze
   * @post Maze object variables are set
   * @param FileName contains the variables that will fill the Maze object
   */
  explicit Maze(const string &FileName);

  /**
   * checks if given location has any markers
   *
   * ' ' means that it's clear
   *
   * @pre maze must be created
   * @post const
   * @param Row to be checked if clear
   * @param Col to be checked if clear
   * @return True if ' ' False otherwise
   */
  bool isClear(int Row, int Col) const;

  /**
   * marks given location with a '*'
   *
   * '*' indicates it is part of the exit path
   *
   * @pre maze must be created
   * @post given location is marked with '*'
   * @param Row to be used to mark '*'
   * @param Col to be used to mark '*'
   * @return void
   */
  void markAsPath(int Row, int Col);

  /**
   * marks given location with a '+'
   *
   * '+' is to indicate Creature has been to that location but it is not a part
   * of the exit path
   *
   * @pre maze must be created
   * @post given location is marked with '+'
   * @param Row to be used to mark '+'
   * @param Col to be used to mark '+'
   * @return void
   */
  void markAsVisited(int Row, int Col);

  /**
   * returns exit row
   *
   * @pre maze must be created with exit row initialized
   * @post const
   * @return the exit row
   */
  int getExitRow() const;

  /**
   * returns exit column
   *
   * @pre maze must be created with exit column initialized
   * @post const
   * @return the exit column
   */
  int getExitColumn() const;

};

#endif //ASS3_MAZE_H
