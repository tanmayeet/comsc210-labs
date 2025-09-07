#include <iostream>
#include <random>
#include <vector>
using namespace std;

struct Color {
  int r_hue;
  int g_hue;
  int b_hue;
};

vector<Color> color;

int randomNum() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, 255);
  int r = dist(gen);  // random red value
  int g = dist(gen);  // random green value
  int b = dist(gen);  // random blue value
}

int main() { return 0; }