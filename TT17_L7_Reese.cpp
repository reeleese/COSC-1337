// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 6  Purpose: Create a class and test it by creating a driver

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class Inventory{
  private:
    //Attributes
    int _itemNumber;
    int _quantity;
    double _cost;
    string _itemDescription;

    //Setters 
    void setItemNumber(int itemNumber) {
      _itemNumber = itemNumber;
    }
    void setQuantity(int quantity) {
      if (quantity >= 0) _quantity = quantity;
      else _quantity = 0;
    }
    void setCost(double cost) {
      if (cost >= 0) _cost = cost;
      else _cost = 0;
    }
    void setItemDescription(string itemDescription) {
      _itemDescription = itemDescription;
    }

  public:
    //Constructor
    Inventory(string itemDescription="noName",
	    int itemNumber=0, int quantity=0, double cost=0) {
      setItemDescription(itemDescription);
      setItemNumber(itemNumber);
      setQuantity(quantity);
      setCost(cost);
    }

    //Getters
    int getItemNumber() const {
      return _itemNumber;
    }
    int getQuantity() const {
      return _quantity;
    }
    double getCost() const {
      return _cost;
    }
    double getTotalCost() const {
      return _cost * _quantity;
    }
    string getItemDescription() const {
      return _itemDescription;
    }
};

//Standardized output for testing
void inventoryDriver_ouput(Inventory& thing) {
  cout << setprecision(2) << fixed
       << "Item Description: " << thing.getItemDescription() << endl
       << "Item Number: " << thing.getItemNumber() << endl
       << "Quantity: " << thing.getQuantity() << endl
       << "Individual Cost: $" << thing.getCost() << endl
       << "Item(s) Total Cost: $" << thing.getTotalCost() << endl;
}

//For ensuring that numeric input is valid 
double get_input(string prompt) {  
  double number{};
  cout << prompt;
  
  //Ensure input is a number
  while (!(cin >> number)) {
    cout << "Value must be an integer." << endl;
    cin.clear();
    cin.ignore(255, '\n');
    cout << prompt; 
  }
  return number;
}

Inventory buildInventory() {
  //Gather desired attributes
  cout << "Item Description: ";
  string itemDescription;
  cin >> itemDescription;

  int itemNumber = get_input("Item Number: ");

  int quantity = int(get_input("Quantity: "));

  double cost = get_input("Cost: $");

  //Create inventory to spec and return
  Inventory item = Inventory(itemDescription, itemNumber, quantity, cost);
  return item;
}

void inventoryDriver() {
  //Container for test Inventory items
  vector<Inventory> items;

  //Loop to create the Inventory(s)
  int itemCount = get_input("Number of items in inventory: ");
  cout << "Please describe the items for testing:" << endl;
  for (int i = 0; i < itemCount; i++) {
    items.push_back(buildInventory());
    cout << endl;
  }

  //Display inventories and calculate total cost of all instances
  double totalCost = 0;
  for (Inventory &item : items) {
    cout << endl;
    inventoryDriver_ouput(item);
    totalCost += item.getTotalCost();
  }

  //Display total cost
  cout << "Total cost of all items: $"
       << setprecision(2) << fixed << totalCost << endl;
      
}

//Main
int main() { 
  inventoryDriver();
  return 0;
}
