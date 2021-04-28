/**
 * @file: main.cpp
 * @brief C++ program to create Summation Tower.
 * @Author: Braden Wolf
 */
#include <iostream>
#include <cassert>


// Function to generate summation tower
void printSummationTower(int arr[], int n) {
  // base case
  if (n == 1) {
    std::cerr << "[" << arr[0] << "]" << std::endl;
    return;
  }

  // fill new array
  int newArr[n - 1];
  for (int i = 0; i < n - 1; i++) {
    newArr[i] = arr[i] + arr[i + 1];
  }

  // recursion
  printSummationTower(newArr, n - 1);

  // print
  std::cerr << "[";
  for (int i = 0; i < n - 1; i++) {
    std::cerr << arr[i] << ", ";
  }
  std::cout << arr[n - 1] << "]" << std::endl;

  return;
}



// Driver function
int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  // print original array
  std::cerr << "Orginal Array: "
            << "[";
  for (int i = 0; i < n - 1; i++) {
    std::cerr << arr[i] << ", ";
  }
  std::cerr << arr[n - 1] << "]" << std::endl << std::endl;

  // call summation tower
  std::cout << "Summation Tower:" << std::endl;
  printSummationTower(arr, n);
}
