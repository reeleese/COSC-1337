// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 4  Purpose:

/*
TODO:
-Add purpose
-Add program output
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

const int min_year{1900};

int main(){
  //Create filestream
  string file_name = "people.txt";
  ifstream my_pop(file_name);
  
  //Container for each population recorded stored in chronological order
  vector<int> populations;
  
  //If file successfully opens
  if (my_pop) {
    string population{};
    while (my_pop >> population)
      populations.push_back(atoi(population.c_str()));
  }
  
  //If file fails to open
  else {
    cout << "Did not successfully open file: " << file_name << endl;
    cout << "Exiting program..." << endl;
    return 1;
  }

  //Close filestream
  my_pop.close();

  //Record maximum population
  int max_pop{0};
  for(int population : populations)
    if (population > max_pop)
      max_pop = population;
  const int max_population = max_pop;

  //Record maximum year
  const int max_year = 1900 + (populations.size() -1) * 20;
  
  //Record the horizontal space needed for y-axis labels
  int y_label_width = to_string(max_population).length();
  
  //Print the y-axis labels and columns
  for (int y_value = max_population; y_value > 0; y_value -= 1000) {
    cout << setw(y_label_width) << y_value;              //print y-axis
    for (int population : populations) {
      cout << (population >= y_value ? " ** " : "    "); //The actual column
      cout << "  ";                                      //space after column
    }
    cout << endl;
  }
  
  // x-axis label offset (the bottom left corner)
  cout << setw(y_label_width) << " "; 
 
  //Print the x-axis labels
  for (int year = min_year; year <= max_year; year += 20)
    cout << year << "  ";
  cout << endl;

  //The end
  return 0;
}

/*
Program Output:

*/
