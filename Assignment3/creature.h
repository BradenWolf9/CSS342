/**
 * @file creature.h
 * @Author Braden Wolf
 * @brief header file for creature class
 */



#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>



/**
 * creature object is what is moved throughout the maze
 *
 * variable Row holds the current row the creature is at
 * variable Col holds the current column the creature is at
 */
class Creature {
public:

  /**
   * prints current location of creature
   *
   * @pre Creature object must be initialized with a row and a column
   * @post doesn't change any variables
   * @param Out is filled with the current row and column of the creature
   * @param Creaature object is used to get it's current row and column
   * @return Returns Out
   */
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
  int Row;
  int Col;

  /**
   * move creature to a new location
   *
   * In order of North, West, South, East, will check if given direction is
   * clear. Will move in the first given direction that is clear. Will add a
   * letter (N,W,S,E) to the Path variable if creature moves in that given
   * direction.
   *
   * @pre Maze must of been created and Path string must have been created
   * @post If creature moves in any of the 4 directions then a '*' will be
   *       added to that location on the maze where the creature moved to.
   * @param Path will have a letter (N,W,S,E) added to it if creature moves
   *        in that given direction.
   * @param Maze object is used to check if creature can move in a given
   *        direction.
   * @return True if creature was able to move to new location or false if
   *         creature was not able to move to new location.
   */
  bool moveForward(std::string &Path, Maze &Maze);

  // backtrack, check last letter on Path then go opposite way
  void backtrack(std::string &Path);

  // checks if creature is at the exit
  bool atExit(const Maze &Maze) const;

  // moves creature north
  void goNorth();

  // moves creature west
  void goWest();

  // moves creature south
  void goSouth();

  // moves creature east
  void goEast();

public:
  /**
   * constructor
   *
   * @pre nothing needs to be done before using this
   * @post creature object will have a row and colomn
   * @param Row used to set object's Row
   * @param Col used to set object's Col
   */
  Creature(int Row, int Col);

  /**
   * has creature solve maze
   *
   * Uses Maze's markAsPath method, Creatur's atExit method, Creature's
   * moveForward method, Maze's markAsVisited method, and Creature's
   * backtrack method to have the creature solve the maze.
   *
   * @pre
   * @post
   * @param Maze
   * @return a string in the form of NNEEN of the path out of the maze
   *         (where N means North, E means East, etc)
   */
  string solve(Maze *Maze);

};

#endif //ASS3_CREATURE_H
