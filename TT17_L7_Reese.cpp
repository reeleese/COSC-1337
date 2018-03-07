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

    //Setters 
    void setItemNumber(int itemNumber) {
      _itemNumber = itemNumber;
    }
    void setQuantity(int quantity) {
      _quantity = quantity;
    }
    void setCost(int cost) {
      _cost = cost;
    }

  public:
    //Constructor
    Inventory(int itemNumber=0, int quantity=0, double cost=0) {
      setItemNumber(itemNumber);
      setQuantity(quantity);
      setCost(cost);
    }

    //Getters
    int getItemNumber() {
      return _itemNumber;
    }
    int getQuantity() {
      return _quantity;
    }
    double getCost() {
      return _cost;
    }
};


int main() {


  return 0;
}
