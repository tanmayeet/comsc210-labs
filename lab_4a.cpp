// COMSC-210 | Lab 4A | Tanmayee Chalamalasetti
// IDE used: VS Code

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int randomNum();  // function prototype

// width for the table
const int width = 10;
// rgb max val
const int rgb_max = 256;
// seperator length
const int sep_length = 40;

// creates a struct with three int variables to represent the RGB values
struct Color {
  int r_hue;
  int g_hue;
  int b_hue;
};

// Generates a random number between 25 and 50
// randomNum() generates a random number between 25 and 50
// arguments: none
// returns: int - the generated random number
int randomNum() {
  // constants for range of random num generator
  const int min = 25;
  const int max = 50;

  return min + rand() % (max - min + 1);
}

int main() {
  // seed the random num generator once
  srand(time(0));
  // n is the random number created using the randomNum function
  int n = randomNum();
  // vector created
  vector<Color> colors;

  // loop to generate 'n' random colors and store them in the vector
  for (int i = 0; i < n; ++i) {
    Color temp;
    temp.r_hue = rand() % rgb_max;
    temp.g_hue = rand() % rgb_max;
    temp.b_hue = rand() % rgb_max;

    // Add the generated color to the vector
    colors.push_back(temp);
  }
  // Output table header for color values
  cout << left << setw(width) << "Color#" << setw(width) << "R value"
       << setw(width) << "G value" << setw(width) << "B value" << endl;

  // Print a separator line for visual clarity
  cout << string(sep_length, '-') << endl;

  // Loop through the vector and display each color's RGB values
  for (int i = 0; i < colors.size(); ++i) {
    cout << left << setw(width) << (i + 1) << setw(width) << colors[i].r_hue
         << setw(width) << colors[i].g_hue << setw(width) << colors[i].b_hue
         << endl;
  }

  return 0;
}