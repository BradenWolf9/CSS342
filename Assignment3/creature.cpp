/**
 * @file creature.cpp
 * @Author Braden Wolf
 * @brief implementation file for creature class
 */



#include "creature.h"
#include <stdlib.h>
#include <iostream>



// prints current location of creature
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  Out << "(" << Creature.Row << "," << Creature.Col << ")";
  return Out;
}



// move creature to a new location
bool Creature::moveForward(std::string &Path, Maze &Maze) {
  bool answer;

  // try north
  if (Maze.isClear(this->Row - 1, this->Col)) {
    this->goNorth();
    Maze.markAsPath(this->Row, this->Col);
    Path.push_back('N');
    answer = true;
  }
  // try west
  else if (Maze.isClear(this->Row, this->Col - 1)) {
    this->goWest();
    Maze.markAsPath(this->Row, this->Col);
    Path.push_back('W');
    answer = true;
  }
  // try south
  else if (Maze.isClear(this->Row + 1, this->Col)) {
    this->goSouth();
    Maze.markAsPath(this->Row, this->Col);
    Path.push_back('S');
    answer = true;
  }
  // try east
  else if (Maze.isClear(this->Row, this->Col + 1)) {
    this->goEast();
    Maze.markAsPath(this->Row, this->Col);
    Path.push_back('E');
    answer = true;
  }
  // no new places to go, so send back false and backtrack
  else {
    answer = false;
  }

  return answer;
}



// backtrack, check last letter on Path then go opposite way
void Creature::backtrack(std::string &Path) {
    // if north go south
  if (Path[Path.length() - 1] == 'N') {
    this->goSouth();
  }
  // if west go east
  else if (Path[Path.length() - 1] == 'W') {
    this->goEast();
  }
  // if south go north
  else if (Path[Path.length() - 1] == 'S') {
    this->goNorth();
  }
  // if east go west
  else {
    this->goWest();
  }

  Path.pop_back();
}



// checks if creature is at the exit
bool Creature::atExit(const Maze &Maze) const {
  return (this->Row == Maze.getExitRow() && this->Col == Maze.getExitColumn());
}



// moves creature north
void Creature::goNorth() {
    this->Row--;
}

// moves creature west
void Creature::goWest() {
    this->Col--;
}

// moves creature south
void Creature::goSouth() {
    this->Row++;
}

// moves creature east
void Creature::goEast() {
  this->Col++;
}



// constructor
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {}



// has creature solve maze
string Creature::solve(Maze *Maze) {
  // Path is used as a STACK
  string Path;
  bool movedForward;

  // Mark starting point as path
  Maze->markAsPath(this->Row, this->Col);

  // Move creature until it reaches the exit
  while(!this->atExit(*Maze)) {
    // try moving to new location
    movedForward = moveForward(Path, *Maze);
    // if can't move to new location then backtrack
    if (!movedForward) {
      Maze->markAsVisited(this->Row, this->Col);
      this->backtrack(Path);
    }
  }
  return Path;
}
