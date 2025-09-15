// COMSC 210 | Lab 7 | Tanmayee Chalamalasetti
// IDE used: VS Code

#include <iostream>
using namespace std;

void reverseArray(string* arr, int size) {
  for (int i = 0; i < size / 2; i++) {  // iterates through array
    int* left_ptr = arr;
    int* right_ptr = arr + size - 1;
  }
}

string displayArray(string* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << *(arr + i) << " ";
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
