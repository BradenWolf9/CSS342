/**
 * @file main.cpp
 * @brief Parade: Implement the function organizeParade() that takes a randomly
 * organized set of parade entrants (random string of f's and b's) and produces
 * a organized interleaved set (string of interleaved f's and b's).  You MUST
 * implement this using the STL stack data structure.
 *
 * @author Matt Wenger
 * @editor Braden Wolf
 */
#include <assert.h>
#include <iostream>
#include <stack>
#define BAND 'b'   // identifier for a band
#define FLOAT 'f'  // identifier for a float
uint outputStrLen; // global variable for expected string length

// Forward declarations
std::string generateEntrants();
void testResult(std::string);

/**
 * Organizes a parade by interleaving bands and floats
 * @param entrants Randomly ordered string of BAND's and FLOAT's
 * @return Interleaved string of BAND's and FLOAT's
 */
std::string organizeParade(std::string entrants) {
  std::string output;

  // Your code goes here...

  std::stack<char> myStack;

  output.push_back(entrants[0]);

  for (unsigned int i = 1; i < entrants.length(); i++) {
    if (myStack.empty()) {
      if (entrants[i] == entrants[i - 1]) {
        myStack.push(entrants[i]);
      } else {
        output.push_back(entrants[i]);
      }
    } else {
      if (entrants[i] == myStack.top()) {
        myStack.push(entrants[i]);
      } else {
        output.push_back(entrants[i]);
        output.push_back(myStack.top());
      }
    }
  }
  return output;
}

/******************************************************/
/***  The functions below are just helper  ************/
/***  functions, you should not edit them! ************/
/******************************************************/
/** * Driver function for organizing a parade */
int main() {
  std::string entrants = generateEntrants();
  std::string parade = organizeParade(entrants);
  testResult(parade);
  return 0;
}

/** Generates a random entrant type; b = band, f = float
 * @return A random character of 'b' or 'f'
 */
char randomEntrant() {
  char entrant;
  if (rand() > (RAND_MAX / 2)) {
    entrant = BAND;
  } else {
    entrant = FLOAT;
  }
  return entrant;
}

/** Generates a string of random entrants; b = band, f = float
 * @return A string containing a randomly organized list of bands 'b'
 * and floats 'f'
 */
std::string generateEntrants() {
  int bands = 0, floats = 0;
  srand(time(NULL));
  int numEntrants = random() % 40 + 10;
  std::string entrants("");
  for (int i = 0; i < numEntrants; i++) {
    char entrant = randomEntrant();
    entrants += entrant;
    if (entrant == BAND)
      bands++;
  }

  floats = numEntrants - bands;
  std::cout << "Generated " << numEntrants << " random entrants of " << bands
            << " bands and " << floats << " floats\n";
  bands >= floats ? outputStrLen = 2 *floats : outputStrLen = 2 * bands;
  std::cout << "Output string length must be >= " << outputStrLen << std::endl;
  std::cout << "Input: " << entrants << std::endl;
  return entrants;
}

/**
 * Tests the output is of correct length and the bands/floats are interleaved
 * @param output String of interleaved characters
 */
void testResult(std::string output) {
  std::cout << "Output: " << output << std::endl;
  std::cout << "Output string length: " << output.length() << std::endl;
  assert(output.length() >= outputStrLen);
  // Test if interleaved
  bool interleaved = true;
  for (uint i = 0; i < output.length() - 1; i++) {
    if (output[i] == output[i + 1]) {
      interleaved = false;
    }
  }
  assert(interleaved);

  // If the program reaches here your function should be working
  std::cout << "Test passed - da iawn ti!" << std::endl;
}
