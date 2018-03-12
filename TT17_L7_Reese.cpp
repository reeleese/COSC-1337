// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 6  Purpose: 

/*
TODO:
-Add purpose





*/

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
};

void inventoryDriver(Inventory& thing, int number, int quantity, double cost) {
  thing = Inventory(number, quantity, cost);
  cout << thing.getItemNumber() << endl
       << thing.getQuantity() << endl
       << thing.getCost() << endl
       << thing.getTotalCost() << endl;
}

int main() { 
  Inventory banana;
  inventoryDriver(banana, 10, 6, 0.3);
  return 0;
}
