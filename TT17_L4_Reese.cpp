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
  bool done = false;
  while (!done) {
    //Menu
    cout << "a)ir, w)water, s)teel or  q)uit" << endl;
    cout << "Option";

    //Get option
    enum Material {air='a', water='w', steel='s', quit='q'};
    Material option;
    //cin >> option;

    //Process option
    switch (option) {
    case air :
      break;
    case water :
      break;
    case steel :
      break;
    case quit :
      break;
    default :
      cout << "Invalid input";
      break;
    }
  }
  return 0;
}
