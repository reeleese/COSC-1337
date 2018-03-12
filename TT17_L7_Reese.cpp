// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 6  Purpose: 

/*
TODO:
-Add purpose
-Test code on a windows machine with devcpp




*/
#include <string>
#include <iostream>
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
    }
    void setCost(double cost) {
      if (cost >= 0) _cost = cost;
    }
    void setItemDescription(string itemDescription) {
      _itemDescription = itemDescription;
    }

  public:
    //Constructor
    Inventory(int itemNumber=0, int quantity=0, double cost=0) {
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
    double getTotalCost() {
      return _cost * _quantity;
    }
    string getItemDescription() {
      return _itemDescription;
    }
};

void inventoryDriver_ouput(Inventory& thing) {
  cout << thing.getItemNumber() << endl
       << thing.getQuantity() << endl
       << thing.getCost() << endl
       << thing.getTotalCost() << endl;
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
    int itemCount = get_input("Number of items in inventory: ");
}


int main() { 
  return 0;
}
