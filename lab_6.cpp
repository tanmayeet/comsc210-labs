// COMSC 210 | Lab 6 | Tanmayee Chalamalasetti
// IDE used: VS Code

#include <iostream>
using namespace std;

// Function prototypes
void enterArrayData(double* arr, int size);
void outputArrayData(double* arr, int size);
double sumArray(double* arr, int size);

void enterArrayData(double* arr, int size) {
  cout << "Data entry for the array:" << endl;
  for (int i = 0; i < size; i++) {  // iterates through array
    cout << "Element #" << i << ": ";
    cin >> *(arr + i);  // using pointer notation instead of array notation
  }
  cout << "Data entry complete." << endl;
}

void outputArrayData(double* arr, int size) {
  cout << "Outputting array elements: " << endl;
  for (int i = 0; i < size; i++) {
    cout << *(arr + i);
  }
}

double sumArray(double* arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += *(arr + i);
  }
  cout << "Sum of values: ";
  return sum;
}

int main() {
  const int size = 5;
  double* arr = new double[size];

  enterArrayData(arr, size);
  outputArrayData(arr, size);
  sumArray(arr, size);

  delete[] arr;
  return 0;
}
