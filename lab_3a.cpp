// COMSC-210 | Lab 3A | Tanmayee Chalamalasetti
// IDE Used: VS Code
#include <iostream>
#include <string>
using namespace std;

// constants for input validation
const int min_price = 1;
const int max_price = 4;
const double min_review = 1.0;
const double max_review = 5.0;

// Restaurant struct with variables representing key pieces of info a customer
// would want when looking at a restaurant
struct Restaurant {
  string address;
  string type;
  int price_range;
  bool veg_options;
  double reviews;
};

Restaurant createRestaurant();             // function prototype
void printRestaurant(const Restaurant r);  // function prototype

// createRestaurant() prompts user for restaurant information and creates a
// Restaurant object arguments: none returns: Restaurant - a Restaurant struct
// populated with user input data
Restaurant createRestaurant() {
  Restaurant temp;
  cout << "Enter address: ";
  getline(cin, temp.address);
  cout << "Enter type of restaurant: ";
  getline(cin, temp.type);

  // get price range with simple validation
  cout << "Enter the price_range of restaurant (1-4): ";
  cin >> temp.price_range;
  while (temp.price_range < min_price || temp.price_range > max_price) {
    cout << "Please enter a number between 1-4: ";
    cin >> temp.price_range;
  }

  // get veg options with validation
  int veg_input;
  cout << "Enter whether the restaurant has vegetarian options or not (1/0): ";
  cin >> veg_input;
  while (veg_input != 0 && veg_input != 1) {
    cout << "Please enter 1 for yes or 0 for no: ";
    cin >> veg_input;
  }
  temp.veg_options = veg_input;

  // get reviews with simple validation
  cout << "Enter the reviews of the restaurant (1.0-5.0): ";
  cin >> temp.reviews;
  while (temp.reviews < min_review || temp.reviews > max_review) {
    cout << "Please enter a rating between 1.0-5.0: ";
    cin >> temp.reviews;
  }

  cin.ignore();  // clear the newline character left in buffer after numeric
                 // input
  return temp;
}

// printRestaurant() displays restaurant information in formatted output
// arguments: Restaurant r - the restaurant object to display
// returns: void
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
  // Four restaurant objects that call the createRestaurant() function
  Restaurant a = createRestaurant();
  Restaurant b = createRestaurant();
  Restaurant c = createRestaurant();
  Restaurant d = createRestaurant();

  // Prints out each Restaurant from user input for the four different objects
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