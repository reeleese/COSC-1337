/*
  Author:
  Assignment:      Lab 10
  Topic:           memory diagram with stack, heap structures
  File Name:
  Course/Section:  COSC 1337
  Due Date:        See syllabus or blackboard
  Instructor:      Thayer
*/

/*
This lab is on pointers. It covers: values, addresses, pointers, the heap,
dynamic memory allocation using new, delete, delete [].
It also has a very brief introduction to linked lists, a basic data structure.

From scratch, create a program that uses memory as shown in the memory diagram
provided. Wherever possible, set the values of all variables indirectly using
pointers. Use pointer dereferencing to set the values of the "pointed to"
variables. You can "dereference" pointers with the '*' operator.  For example,
to set price to $19.95, do NOT use the variable price. Instead, use the pointer
variable *p_price. To set pi_div_2, dereference p_PI to get 3.141592, divide it
by two, and place the result into PI_div_2.

To create the "linked list" containing Person "Harry" and Person "Sally",
you need the following data structure:

class Person {
  string name;       // name of the person
  Person *next;    // pointer to the next person in the list
};

To create instances of Person, you will use:
  1)  static allocation:  Person wizard will be on the stack;
  2) dynamic allocation: Persons "Harry" and "Sally" are allocated on the heap

To manipulate an object of class Person, you need to create some constructors,
getters and setters to fill in the name and set the pointers, or, you could make
the data members public and use  "dot" notation, such as: Person wizard;
wizard.name="Gandalf"; wizard.next=nullptr;
For dynamically allocated instances, you can use arrow notation,
such as: personList -> name="Harry".

The keyword nullptr is the C++11/14 recommended way of setting a pointer to NULL or 0.

To create variables on the heap, with no names, you have to use new to dynamically
allocate the memory. See sample output (bottom page). IMPORTANT: Every new should
be matched by a delete to prevent a memory leak! IMPORTANT: Make sure you delete
all memory you dynamically allocate before leaving main(). Don't allow any memory
leaks. Match all new with delete. When deleting an array, use delete [] array.

After items are placed in memory, use cout statements to output the addresses
and values of all variables. Output the addresses of all variables
(both pointer and named) in hexadecimal format, and output the contents (values)
of all int, float, double and string variables.

You cannot force the memory layout to be exactly in the order in the memory diagram.
As a programmer, you don't  control exactly WHERE in memory the compiler places
variables. The important thing is for you to create the pointer variables,
value variables, and set them up (nearly) as depicted in the memory diagram.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Person {
  public:
    string name;     // name of the person
    Person *next;    // pointer to the next person in the list
};

// Helpful macros to make it easier to output name, address, and value of a variable
// You may use these, or write your own function that does something similar
#define show_addr_value(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<&var<<"  "     \
      <<"contents of "<<setw(width)<<left<<#var<<" is: "<<var<<endl;

#define show_addr(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<&var<<endl;

int main () {
  cout << "Output from Lab10 memory diagram on pointers:\n\n";
  
  float price = 0;
  float *p_price = &price;
  *p_price = 19.95;
  show_addr_value(price, 8);
  show_addr_value(p_price, 8);
  cout << "The contents of *p_price is: " << *p_price << endl;

  /* Output comments, formats results, use as desired.
  cout << "The contents of *p_PI is:    " << *p_PI << endl;
  cout << "The contents of *p_amount is: " << (dec) << *p_amount << endl;
  cout << "After delete, the contents of p_amount is: " << p_amount << endl;
  cout << "After reset to nullptr, the contents of p_amount is: " << p_amount << endl;
  cout << "After delete [], the contents of pArray is: " << pArray << endl;
  cout << "After reset to nullptr, the contents of pArray is: " << pArray << endl;
  cout<<"static (uses: Person wizard):\n";
  cout<<"dynamic (uses: personList, Person(\"Harry\"), Person(\"Sally\"):\n";
  cout << "  <follow link to next Person on personList>\n";
  */
  
  return 0;
} // end of main

/*
Output from Lab10 memory diagram on pointers:

address of price    is: &0x22fe1c  contents of price    is: 19.95
address of p_price  is: &0x22fe10  contents of p_price  is: 0x22fe1c
The contents of *p_price is: 19.95
*/
