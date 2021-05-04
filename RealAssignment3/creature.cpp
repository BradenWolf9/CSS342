// Author: Braden Wolf
// Description: implementation file for creature class
// Date: 5/3/21


#include "creature.h"

// prints current location of creature
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  Out << "(" << Creature.Row << "," << Creature.Col << ")";
  return Out;
}

// constructor
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {}

// returns a string in the form of NNEEN of the path out of the maze
// (where N means North, E means East, etc)
string Creature::solve(Maze *Maze) {
  string Path;

  // Move creature until it has no new places to move or it reaches the exit,
  // backtrack if no new places to move
  while(!this->atExit(*Maze)) {
    // north
    if (Maze->isClear(this->Row - 1, this->Col)) {
      Maze->markAsPath(this->Row, this->Col);
      this->goNorth();
      Path.push_back('N');
    }
    // south
    else if (Maze->isClear(this->Row + 1, this->Col)) {
      Maze->markAsPath(this->Row, this->Col);
      this->goSouth();
      Path.push_back('S');
    }
    // west
    else if (Maze->isClear(this->Row, this->Col - 1)) {
      Maze->markAsPath(this->Row, this->Col);
      this->goWest();
      Path.push_back('W');
    }
    // east
    else if (Maze->isClear(this->Row, this->Col + 1)) {
      Maze->markAsPath(this->Row, this->Col);
      this->goEast();
      Path.push_back('E');
    }
    // if made it to here then no new places to go, so backtrack
    else {
      Maze->markAsVisited(this->Row, this->Col);

      if (Path[Path.length() - 1] == 'N') {
        this->goSouth();
      }
      else if (Path[Path.length() - 1] == 'S') {
        this->goNorth();
      }
      else if (Path[Path.length() - 1] == 'W') {
        this->goEast();
      }
      else {
        this->goWest();
      }
      Path.pop_back();
    }
  }
  return Path;
}

// checks if creature is at the exit
bool Creature::atExit(const Maze &Maze) const {
  return (this->Row == Maze.getExitRow() && this->Col == Maze.getExitColumn());
}

// moves creature north
void Creature::goNorth() {
  this->Row--;
}

// moves creature south
void Creature::goSouth() {
  this->Row++;
}

// moves creature west
void Creature::goWest() {
  this->Col--;
}

// moves creature east
void Creature::goEast() {
  this->Col++;
}
