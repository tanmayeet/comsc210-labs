// COMSC 210 | Lab 6 | Tanmayee Chalamalasetti
// IDE used: VS Code

#include <iostream>
using namespace std;

// Function prototypes
int enterArrayData(double* arr, int size);
int outputArrayData(double* arr, int size);
void sumArray(double* arr, int size);

void enterArrayData(double* arr, int size) {
  double* array[size] = new double[size];
  cout << "Data entry for the array:" << endl;

  for (int i = 0; i < size; i++) {
    cout << "Element #" << i << ":";
    cin >> *(arr + i);
  }
}

void outputArrayData(double* arr, int size) {
  double* arr[size] = new double[size];
}

double sumArray(double* arr, int size) {
  double* arr[size] = new double[size];
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum = arr[i]
  }
}
int main(

    const int size = 5;

) {
  return 0;
}
