#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Color {
  int r_hue;
  int g_hue;
  int b_hue;
};

int randomNum() {
  const int min = 25;
  const int max = 50;

  srand(time(0));

  return min + rand() % (max - min + 1);
}

int main() {
  int n = randomNum();

  vector<Color> colors;

  for (int i = 0; i < n; ++i) {
    Color temp;
    temp.r_hue = rand() % 256;
    temp.g_hue = rand() % 256;
    temp.b_hue = rand() % 256;

    colors.push_back(temp);
  }

  cout << left << setw(10) << "Color#" << setw(10) << "R value" << setw(10)
       << "G value" << setw(10) << "B value" << endl;

  cout << string(40, '-') << endl;

  for (int i = 0; i < colors.size(); ++i) {
    cout << left << setw(10) << (i + 1) << setw(10) << colors[i].r_hue
         << setw(10) << colors[i].g_hue << setw(10) << colors[i].b_hue << endl;
  }

  return 0;
}