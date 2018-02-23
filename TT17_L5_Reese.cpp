// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 4  Purpose:

/*
TODO:
-Add purpose
-Add program output
*/

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

const int year0{1900};

int main(){
  //Read in people.txt
  string file_name = "people.txt";
  ifstream my_pop("people.txt");
  
  //Container for each population recorded stored in chronological order
  vector<int> populations;
  
  if (my_pop) {
    string population{};
    while (my_pop >> population)
      populations.push_back(atoi(population.c_str()));
  }
  my_pop.close();

  //Record maximum population
  int max_population{0};
  for(int population : populations)
    if (population > max_population)
      max_population = population;


  return 0;
}

/*
Program Output:

*/
