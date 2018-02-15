
// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 4  Purpose: 

/*
TODO:
-Add purpose
-Read file contents
*/

#include  <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  //Read in file
  string filename = "lab4_info.txt";
  ifstream speeds{filename};

  vector<string> file_contents;
  if (speeds) {
    string item = "notAnInt";
    while (speeds >> item) {
      file_contents.push_back(item);
    }
  }

  vector<string> options;
  for (int i = 0; i < file_contents.size(); i += 2) {
    options.push_back(file_contents[i]);
    
  }

  /*
  //Material enum
  enum Material {air='a', water='w', steel='s', quit='q'};
  
  //Loop
  bool done = false;
  while (!done) {
    //Get material
    cout << "a)ir, w)water, s)teel or  q)uit" << endl;
    cout << "Option: ";
    char tmp;
    cin >> tmp;
    Material option = static_cast<Material>(tmp);

    //Get thickness
    cout << "How thick is the matarial (in feet): ";
    double thickness;
    cin >> thickness;

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
      cout << "Invalid input.";
      break;
    }
  }
  */
  return 0;
}
