// COMSC 210 | Lab 7 | Tanmayee Chalamalasetti
// IDE used: VS Code

#include <iostream>
using namespace std;

// Function prototypes
void reverseArray(string* arr, int size);
void displayArray(string* arr, int size);

// reverseArray uses a for loop set to iterate through the array reverse its
// elements arguments: string* arr, int size returns nothing
void reverseArray(string* arr, int size) {
  string temp;
  for (int i = 0; i < size / 2;
       i++) {           // iterates through half the array to avoid redundancy
    temp = *(arr + i);  // initializes a temporary position at the start (moves
                        // the start over by one each time the loop iterates)
    *(arr + i) = *(arr + size - 1 - i);  // sets the start (wherever that is) to
                                         // the end variable (size - 1 - i)
    *(arr + size - 1 - i) = temp;  // vice versa but now with the end element
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
