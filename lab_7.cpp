// COMSC 210 | Lab 7 | Tanmayee Chalamalasetti
// IDE used: VS Code

#include <iostream>
using namespace std;

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

string displayArray(string* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << *(arr + i) << " ";
  }
}

int main() {
  const int size = 5;
  string* arr = new string[size];

  cout << "Original array: ";
  for (int i = 0; i < size; i++) {
    cout << *(arr + i) << " ";
  }

  reverseArray(arr, size);

  cout << "Reversed array: ";
  displayArray(arr, size);

  return 0;
}
