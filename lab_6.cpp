// COMSC 210 | Lab 6 | Tanmayee Chalamalasetti
// IDE used: VS Code

#include <iostream>
using namespace std;

// Function prototypes
void enterArrayData(double* arr, int size);
void outputArrayData(double* arr, int size);
double sumArray(double* arr, int size);

// enterArrayData takes in user inputted data for each element of the array
// (for a certain size that is also inputted) and prints it with guiding text
// also trying to validate
// arguments: double* arr, int size returns: nothing,
// but prints out to array input with some guiding text
void enterArrayData(double* arr, int size) {
  cout << "Data entry for the array:" << endl;

  for (int i = 0; i < size; i++) {  // iterates through array
    cout << "Element #" << i << ": ";
    while (!(cin >> *(arr + i))) {  // input validation
      cin.clear();                  // resets the stream
      cin.ignore(1000, '\n');       // discards any bad inputs
      cout << "Invalid input. Please enter a number for Element #" << i << ": "
           << endl;
    }
  }
  cout << "Data entry complete." << endl;
}

// outputArrayData takes in a double array and outputs all of its elements on
// one line (with spaces in between) arguments: double* arr, int size returns:
// nothing, but prints out to array input with some guiding text
void outputArrayData(double* arr, int size) {
  cout << "Outputting array elements: ";
  for (int i = 0; i < size; i++) {
    cout << *(arr + i) << " ";
  }
  cout << endl;
}

// sumArray takes in the double array and adds all of its elements together and
// prints out the sum arguments: double* arr, int size returns: the sum of all
// the values in a double variable called sum
double sumArray(double* arr, int size) {
  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += *(arr + i);
  }
  return sum;
}

int main() {
  // initializing two variables, one is a constant int for a size parameter for
  // the array, another is initializing a new double array pointer
  const int size = 5;
  double* arr = new double[size];

  // calling the functions with the variables we initialized earlier
  enterArrayData(arr, size);
  outputArrayData(arr, size);
  double total = sumArray(arr, size);
  cout << "Sum of values: " << total << endl;

  // deleting the array to free memory space
  delete[] arr;
  return 0;
}
