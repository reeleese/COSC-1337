// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 6  Purpose: 

/*
TODO:
-Add purpose
-Test code on a windows machine with devcpp




*/
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class Inventory{
  private:
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

void inventoryDriver_ouput(Inventory& thing) {
  cout << setprecision(2) << fixed
       << "Item Description: " << thing.getItemDescription() << endl
       << "Item Number: " << thing.getItemNumber() << endl
       << "Quantity: " << thing.getQuantity() << endl
       << "Individual Cost: " << thing.getCost() << endl
       << "Item(s) Total Cost: " << thing.getTotalCost() << endl;
}

int get_input(string prompt) {  
  int itemCount{};
  cout << prompt;
  
  //Ensure input is an int
  while (!(cin >> itemCount)) {
    cout << "Value must be an integer." << endl;
    cin.clear();
    cin.ignore(255, '\n');
    cout << prompt; 
  }

  return itemCount;
}

void inventoryDriver() {
  //Test Items
  Inventory item0 = Inventory();
  Inventory item1 = Inventory("bananas", 42, 8, 0.244);
  Inventory item2 = Inventory("skillet", 101, 1, 34.99);
  Inventory item3 = Inventory("Bad Item", 666, -15, -6.6666);
  Inventory item4 = Inventory("Tabloid", 121, 3, 11.306);

  Inventory invItems[5] = {item0, item1, item2, item3, item4};
  double totalCost = 0;
  
  int itemCount = get_input("Number of items in inventory: ");
  for(int i = 0; i < itemCount; i++) {
    inventoryDriver_ouput(invItems[i]);
    totalCost += invItems[i].getTotalCost();
    cout << endl;
  }

  cout << "Total cost of all items: $"
       << setprecision(2) << fixed << totalCost << endl;
      
}


int main() { 
  inventoryDriver();
  return 0;
}
