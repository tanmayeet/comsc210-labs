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

Restaurant createRestaurant() {
  Restaurant temp;
  cout << "Enter address: ";
  getline(cin, temp.address);
  cout << "Enter type of restaurant: ";
  getline(cin, temp.type);
  cout << "Enter the price_range of restaurant (1-4): ";
  cin >> temp.price_range;
  cout << "Enter whether the restaurant has vegetarian options or not (1/0): ";
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
  cout << "Veg Options: ";
  if (r.veg_options) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  cout << "Reviews: " << r.reviews << endl;
}

int main() {
  Restaurant a = createRestaurant();
  Restaurant b = createRestaurant();
  Restaurant c = createRestaurant();
  Restaurant d = createRestaurant();

  cout << "\nRestaurant A:\n";
  printRestaurant(a);
  cout << "\nRestaurant B:\n";
  printRestaurant(b);
  cout << "\nRestaurant C:\n";
  printRestaurant(c);
  cout << "\nRestaurant D:\n";
  printRestaurant(d);

  return 0;
}