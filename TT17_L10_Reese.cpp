/*
  Author:          Lee Reese
  Assignment:      Lab 10
  Topic:           memory diagram with stack, heap structures
  File Name:       TT17_L10_Reese.cpp
  Course/Section:  COSC 1337
  Due Date:        Thursday 4/26
  Instructor:      Thayer
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Person {
  public:
    string name;     // name of the person
    Person *next;    // pointer to the next person in the list  
};

// MACROS
#define show_addr_value(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<&var<<"  "     \
      <<"contents of "<<setw(width)<<left<<#var<<" is: "<<var<<endl;

#define show_addr(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<&var<<endl;

// MAIN
int main () {
  cout << "Output from Lab10 memory diagram on pointers:\n\n";

  //----PRICE----//
  // Initialize price using pointer p_price
  float price{};
  float* p_price = &price;
  *p_price = 19.95;

  // Price output
  show_addr_value(price, 8);
  show_addr_value(p_price, 8);
  cout << "The contents of *p_price is: " << *p_price << endl;
  cout << endl;

  //----PI & PI_DIV_2----//
  // Initialize PI using point p_PI
  double PI = 0;
  double* p_PI = &PI;
  *p_PI = 3.141592;

  // PI output
  show_addr_value(PI, 8);
  show_addr_value(p_PI, 8);
  cout << "The contents of *p_PI is: " << *p_PI << endl;
  cout << endl;

  // Initialize PI_div_2
  double PI_div_2 = *p_PI / 2;

  // Pi_div_2 output
  show_addr_value(PI_div_2, 8);
  cout << endl;

  //----MAXSIZE & P_AMOUNT----//
  // Initialize maxSize using pointer p_size
  int maxSize = 0;
  int *p_size = &maxSize;
  *p_size = 5028;

  // maxSize output
  show_addr_value(maxSize, 8);
  show_addr_value(p_size, 8);
  cout << "The contents of *p_size is: " << *p_size << endl;
  cout << endl;

  // Initialize p_amount and allocate memory on the heap
  int *p_amount = nullptr;
  p_amount = new int;
  *p_amount = 1234;

  // p_amount output
  show_addr_value(p_amount, 8);
  cout << "The contents of *p_amount is: " << *p_size << endl;
  cout << endl;

  // p_amount delete
  delete p_amount;
  p_amount = nullptr;

  //----PARRAY----//
  // Initialize pArray (+elements) and allocate memory on the heap
  int* pArray = nullptr;
  pArray = new int[3];
  pArray[0] = 11; pArray[1] = 22; pArray[2] = 33;

  // pArray output (82 columns wide)
  show_addr_value(pArray, 9);
  show_addr_value(pArray[0], 9);
  show_addr_value(pArray[1], 9);
  show_addr_value(pArray[2], 9);
  cout << "The contents of *pArray is: " << *pArray << endl;  
  cout << endl;

  // pArray delete
  delete [] pArray;
  pArray = nullptr;

  //----EMPTYLIST----//
  // emptyList + output
  Person* emptyList = nullptr;
  show_addr_value(emptyList, 8);
  cout << endl;

  //----WIZARD----//
  // Initialize wizard using dot notation
  Person wizard;
  wizard.name = "Gandalf";
  wizard.next = nullptr;

  // wizard output
  show_addr(wizard, 11);
  show_addr_value(wizard.name, 11);
  show_addr_value(wizard.next, 11);
  cout << endl;

  //----PERSONLIST----//
  // Initialize personList head
  Person* personList = nullptr;
  personList = new Person;
  personList -> name = "Harry";
  personList -> next = new Person;

  // Initialize second entry in personList
  Person* personList2 = personList -> next;
  personList2 -> name = "Sally";
  personList2 -> next = nullptr;

  // personList output (102 columns wide)
  show_addr_value(personList, 19);
  show_addr_value(personList -> name, 19);
  show_addr_value(personList -> next, 19);
  show_addr_value(personList2, 19);
  show_addr_value(personList2 -> name, 19);
  show_addr_value(personList2 -> next, 19);
  cout << endl;

  // personList delete
  delete personList;
  delete personList2;
  personList = nullptr;
  personList2 = nullptr;
  
  return 0;
} // end of main

/*
Output from Lab10 memory diagram on pointers:

address of price    is: &0x7ffee928488c  contents of price    is: 19.95
address of p_price  is: &0x7ffee9284880  contents of p_price  is: 0x7ffee928488c
The contents of *p_price is: 19.95

address of PI       is: &0x7ffee9284858  contents of PI       is: 3.14159
address of p_PI     is: &0x7ffee9284850  contents of p_PI     is: 0x7ffee9284858
The contents of *p_PI is: 3.14159

address of PI_div_2 is: &0x7ffee9284828  contents of PI_div_2 is: 1.5708

address of maxSize  is: &0x7ffee9284814  contents of maxSize  is: 5028
address of p_size   is: &0x7ffee9284808  contents of p_size   is: 0x7ffee9284814
The contents of *p_size is: 5028

address of p_amount is: &0x7ffee92847e0  contents of p_amount is: 0x7fdd97c02740
The contents of *p_amount is: 5028

address of pArray    is: &0x7ffee92847c8  contents of pArray    is: 0x7fdd97c02740
address of pArray[0] is: &0x7fdd97c02740  contents of pArray[0] is: 11
address of pArray[1] is: &0x7fdd97c02744  contents of pArray[1] is: 22
address of pArray[2] is: &0x7fdd97c02748  contents of pArray[2] is: 33
The contents of *pArray is: 11

address of emptyList is: &0x7ffee9284780  contents of emptyList is: 0x0

address of wizard      is: &0x7ffee9284750
address of wizard.name is: &0x7ffee9284750  contents of wizard.name is: Gandalf
address of wizard.next is: &0x7ffee9284768  contents of wizard.next is: 0x0

address of personList          is: &0x7ffee9284718  contents of personList          is: 0x7fdd97c02750
address of personList -> name  is: &0x7fdd97c02750  contents of personList -> name  is: Harry
address of personList -> next  is: &0x7fdd97c02768  contents of personList -> next  is: 0x7fdd97c02770
address of personList2         is: &0x7ffee9284710  contents of personList2         is: 0x7fdd97c02770
address of personList2 -> name is: &0x7fdd97c02770  contents of personList2 -> name is: Sally
address of personList2 -> next is: &0x7fdd97c02788  contents of personList2 -> next is: 0x0
*/
