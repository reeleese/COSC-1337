// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 4  Purpose: 

/*
TODO:
-Add purpose
-enum for options
-create data file
-cin to option somehow
*/

#include  <iostream>
using namespace std;

int main() {
  enum Material {air='a', water='w', steel='s', quit='q'};
  
  //Loop
  bool done = false;
  while (!done) {
    //Menu
    cout << "a)ir, w)water, s)teel or  q)uit" << endl;
    cout << "Option: ";

    //Get option

    char tmp;
    cin >> tmp;
    Material option = static_cast<Material>(tmp);

    //Process option
    switch (option) {
    case air :
      cout << "air.";
      break;
    case water :
      cout << "water.";
      break;
    case steel :
      cout << "steel.";
      break;
    case quit :
      cout << "quit.";
      break;
    default :
      cout << "Invalid input";
      break;
    }
  }
  return 0;
}
