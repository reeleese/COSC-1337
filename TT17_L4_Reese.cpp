
// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 4  Purpose: 

/*
TODO:
-Add purpose
-Rename data file
-Create prompt
*/

#include  <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main() {
  //Read in file
  string filename = "lab4_info.txt";
  ifstream speeds{filename};

  //Read file into a vector file_contents
  vector<string> file_contents;
  if (speeds) {
    string item = "notAnInt";
    while (speeds >> item) {
      file_contents.push_back(item);
    }
  }
  
  //Print menu, map materials to their respective speeds
  string menu = "Select a material: ";
  map<char, int> options;
  for (int i = 0; i < file_contents.size(); i += 2){
    //Print the materials and speeds
    cout << file_contents[i] << "\t" << file_contents[i+1] << endl;

    //Skip table headings and map information
    if (i > 1) {
      //Create map
      char key = tolower(file_contents[i][0]);
      int value = atoi(file_contents[i+1].c_str());
      options[key] = value;
      
      //Menu
      string tmp = file_contents[i];
      tmp.insert(1, ")");
      menu = menu + tmp + ", ";
    }
  }
  
  menu.resize(menu.size() -2);
  //Loop
  bool done = false;
  while (!done) {
    cout << menu << endl;
    //Get thickness
    cout << "How thick is the matarial (in feet): ";
    double thickness;
    cin >> thickness;

  }
  return 0;
}
