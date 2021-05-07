/**
 * @file creature.h
 * @Author Braden Wolf
 * @brief implementation file for maze class
 */



#include "maze.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;



// prints ASCII display of maze
ostream &operator<<(ostream &Out, const Maze &Maze) {
  for (int Row = 0; Row < Maze.Height; ++Row) {
    for (int Col = 0; Col < Maze.Width; ++Col) {
        Out << Maze.Field[Row][Col];
    }
    Out << endl;
  }
  Out << endl;
  return Out;
}



// For Clion, need the following line in CMakeLists.txt so maze.txt is found
// at the same location as the cpp files
// # need to load data files from current directory as cpp files
// set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})



// constructor
Maze::Maze(const string &FileName) : Field{}, Width{0}, Height{0}, ExitRow{0},
                                     ExitColumn{0}  {
  ifstream InFile;
  InFile.open(FileName);
  if (!InFile) {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }
  InFile >> this->Width >> this->Height;
  InFile >> this->ExitRow >> this->ExitColumn;
  string Str;
  getline(InFile, Str);
  for (int Row = 0; Row < Height; ++Row) {
    for (int Col = 0; Col < Width; ++Col) {
      InFile.get(Field[Row][Col]);
      // cout << Row << ", " << col << ": " << field[Row][col] << endl;
    }
    getline(InFile, Str);
  }
}



// checks if given location has any markers
bool Maze::isClear(int Row, int Col) const {
  return Field[Row][Col] == ' ';
}

// marks given location with a '*'
void Maze::markAsPath(int Row, int Col) {
  Field[Row][Col] = '*';
}

// marks given location with a '+'
void Maze::markAsVisited(int Row, int Col) {
  Field[Row][Col] = '+';
}



// returns exit row
int Maze::getExitRow() const {
  return ExitRow;
}

// returns exit column
int Maze::getExitColumn() const {
  return ExitColumn;
}
