// COMSC 210 | Lab 7 | Tanmayee Chalamalasetti
// IDE used: VS Code

#include <iostream>
using namespace std;

// Function prototypes
void reverseArray(string* arr, int size);
void displayArray(string* arr, int size);

// reverseArray takes in a pointer to a string array and an int size and uses a
// for loop set to iterate through half of the array and each time it does, it
// switches valus with element whose position is the same distanc from the
// midpoint as the temp variable (i.e. 1 & 5 are both 2 away from its midpoint
// of 3, 2 & 4 as well)
// arguments: string* arr, int size
// returns nothing
void reverseArray(string* arr, int size) {
  string temp;
  for (int i = 0; i < size / 2;
       i++) {  // iterates through half the array (doesn't need to do more as it
               // only reverses the element (size / 2) times)
    temp = *(arr + i);  // initializes a temporary position at the start (moves
                        // the start over by one each time the loop iterates)
    *(arr + i) = *(arr + size - 1 -
                   i);  // sets the start (wherever that is) to the end variable
                        // (size - 1 (to avoid out of bound issues as we always
                        // start at 0) - i (depending on where we start aka what
                        // iteration of the for loop this is))
    *(arr + size - 1 - i) =
        temp;  // vice versa but now with the end element (but end goes down by
               // 1 each time we iterat through the loop as we are trying to
               // reverse the )
  }
}

// displayArray uses a for loop to print out a given array based on its
// parameters arguments: string* arr, int size
// returns nothing, but prints out the array arr
void displayArray(string* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << *(arr + i) << " ";
  }
  cout << endl;
}

int main() {
  // initialized 1) a constant int for size 2) a pointer for a string array with
  // a size of our const "size" 3) set the elements of the array with the names
  // given in the example
  const int size = 5;
  string* arr = new string[size];
  *(arr + 0) = "Janet";
  *(arr + 1) = "Jeffe";
  *(arr + 2) = "Jin";
  *(arr + 3) = "Joe";
  *(arr + 4) = "Junio";

  // Displays the original array by calling the displayArray function with some
  // guiding text
  cout << "Original array: ";
  displayArray(arr, size);

  // reverses the elments in the array by calling the reverseArray function
  reverseArray(arr, size);

  // Displays the reversed array by calling the displayArray function with some
  // guiding text
  cout << "Reversed array: ";
  displayArray(arr, size);

  // deletes the dynamically allocated array to free up memory
  delete[] arr;
  return 0;
}
