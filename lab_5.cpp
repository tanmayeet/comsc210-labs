// COMSC-210 | Lab 5 | Tanmayee Chalamalasetti
// IDE Used: VS Code

#include <iostream>
using namespace std;

// Function prototype with two pointer parameters
// Swaps values
int swap(int*, int*);  // First, I changed this from & -> * to change our
                       // reference variable to an actual pointer variable.

// Main function that prints the original value, then a "Swapping..." text, then
// the values swapped using the swap function
int main() {
  int x = 5, y = 10;
  cout << "x = " << x << "  | y = " << y << endl;

  cout << "Swapping...\n";
  int sum = swap(&x, &y);  // Wrote these as the addresses of the variables
                           // instead of the variables alone (aka pointers)
  cout << "x = " << x << " | y = " << y << endl;
  cout << "sum = " << sum << endl;
  return 0;
}

// This function swaps the values put in the parameter and then returns its sum.
int swap(int* a, int* b) {  // changed these to pointer values
  int temp = *a;
  *a = *b;
  *b = temp;
  return *a + *b;
}