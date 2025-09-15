// COMSC 210 | Lab 6 | Tanmayee Chalamalasetti
// IDE used: VS Code

#include <iostream>
using namespace std;

// Function prototypes
void enterArrayData(double* arr, int size);
void outputArrayData(double* arr, int size);
double sumArray(double* arr, int size);

// enterArrayData takes in user inputted data for each element of the array (for
// a certain size that is also inputted) and prints it with guiding text
// arguments: double* arr, int size
// returns: nothing, but prints out to array input with some guiding text
void enterArrayData(double* arr, int size) {
  cout << "Data entry for the array:" << endl;
  for (int i = 0; i < size; i++) {  // iterates through array
    cout << "Element #" << i << ": ";
    cin >> *(arr + i);  // using pointer notation instead of array notation
  }
  cout << "Data entry complete." << endl;
}

// outputArrayData takes
// arguments: double* arr, int size
// returns: nothing, but prints out to array input with some guiding text
void outputArrayData(double* arr, int size) {
  cout << "Outputting array elements: ";
  for (int i = 0; i < size; i++) {
    cout << *(arr + i) << " ";
  }
  cout << endl;
}

double sumArray(double* arr, int size) {
  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += *(arr + i);
  }
  cout << "Sum of values: " << sum << endl;
  return sum;
}

int main() {
  // initializing two variables, one is a constant int for a size parameter for
  // the array, another is initializing a new double array pointer
  const int size = 5;
  double* arr = new double[size];

  //
  enterArrayData(arr, size);
  outputArrayData(arr, size);
  sumArray(arr, size);

  delete[] arr;
  return 0;
}
