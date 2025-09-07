#include <iostream>
#include <string>
using namespace std;

struct Restaurant {
  string address;
  string type;
  int price_range;
  bool veg_options;
  double reviews;
};

Restaurant createRest() {
  Restaurant temp;
  cout << "Enter address: ";
  getline(cin, temp.address);
  cout << "Enter type of restaurant: ";
  getline(cin, temp.type);
  cout << "Enter the price_range of restaurant (1-4): ";
  cin >> temp.price_range;
  cout << "Enter whether the restaurant has vegetarian options or not (1 for "
          "Yes, 0 for No): ";
  cin >> temp.veg_options;
  cout << "Enter the reviews of the restaurant (1.0-5.0): ";
  cin >> temp.reviews;
  cin.ignore();
  return temp;
}

void printRestaurant(const Restaurant r) {
  cout << "Address: " << r.address << endl;
  cout << "Type: " << r.type << endl;
  cout << "Price Range: " << r.price_range << endl;
  cout << "Veg Options: " << (r.veg_options ? "Yes" : "No") << endl;
  cout << "Reviews: " << r.reviews << endl;
}

int main() {
  Restaurant r1 = createRest();
  Restaurant r2 = createRest();
  Restaurant r3 = createRest();
  Restaurant r4 = createRest();

  cout << "\nRestaurant 1:\n";
  printRestaurant(r1);
  cout << "\nRestaurant 2:\n";
  printRestaurant(r2);
  cout << "\nRestaurant 3:\n";
  printRestaurant(r3);
  cout << "\nRestaurant 4:\n";
  printRestaurant(r4);

  return 0;
}