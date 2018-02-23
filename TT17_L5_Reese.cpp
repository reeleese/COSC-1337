// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 4  Purpose:

/*
TODO:
-Add purpose
-Add program output
-Calculate y-label width dynamically
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

const int min_year{1900};

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
  
  //Record maximum year
  const int max_year = 1900 + (populations.size() -1) * 20;
  
  int y_label_width = 5;
  
  //Print the y-axis and bars
  for (int i = max_population; i > 0; i-=1000) {
    cout << setw(y_label_width) << i;
    for (int population : populations) {
      cout << (population >= i ? " ** " : "    ");
      cout << "  ";
    }
    cout << endl;
  }
  
  //Print the x-axis
  cout << setw(y_label_width) << " ";
  for (int year = min_year; year <= max_year; year += 20)
    cout << year << "  ";
  cout << endl;

  return 0;
}

/*
Program Output:

*/
