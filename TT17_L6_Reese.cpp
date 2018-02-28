// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 6  Purpose: Calculate the distance between two things

/*
TODO:
-Purpose
-Program output

*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

//Variables
bool first_input;
float first;
float second;

//Display Counts
static int display_char{0}; 
static int display_number{0}; 
static int display_point{0}; 

//Error Messages
const string error_char = "  Sorry, character must be alphabetic. Try again.";
const string error_number = "Sorry, out-of-range. Try again.";
const string error_point = "This error should never happen.";

//Prompts
const string prompt_char = "Gimme a character: ";
const string prompt_number = "Gimme a number";
const string prompt_point = "";

//Input Functions
char input(string error_message) {
  //Prompt
  cout << (first_input ? "Enter first letter ":"Enter second letter ")
       << "(a to z): ";
  
  //Input
  char user_input{};
  cin >> user_input;
  
  //If char is not a-z or A-Z, try again.
  if (!isalpha(user_input)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << error_message << endl;
    return input(error_message);
  }
  return user_input;
}

float input(float min, float max, string error_message) {
  //Prompt
  cout << (first_input ? "Enter first number ":"Enter second number ")
       << "(" << min << ", " << max << "): ";
  
  //Get Number
  float user_input{};
  cin >> user_input;

  //If user is not in range, try again.
  if (!(min <= user_input <= max)) {
    cout << error_message << endl;
    return input(error_message);
  }

  first_input = false;
  return user_input;
}

void input(double &x, double &y, string error_message) {
  //Prompt
  string iteration = (first_input ? "first" : "second");
  
  //Input
  string user_x{};
  do {
    cout << "Enter the "<< iteration << " point (x): ";
    
  } while (!(cin >> x));

  cout << "Enter the " << iteration << " point (y): ";
  cin >> y;
}

//Distance functions
int dist(char a, char b) {
  int a_num = int (tolower(a));
  int b_num = int (tolower(b));
  return abs(a_num - b_num);
}
float dist(float a, float b) {
  return abs(a - b);
}
float dist(double x1, double y1, double x2, double y2) {
  double a_squared = pow(x2-x1, 2);
  double b_squared = pow(y2-y1, 2);
  return sqrt(a_squared + b_squared);

}

//Display functions


int main() {
  //Display program purpose
  cout << "Display the distance between two itms: lettersn numbers, or points."
       << "\n\n";

  //Sentinel
  char option{};
  
  //Menu
  do {
    //Prompt
    cout << "Options: l)etter; n)umber; p)oint; q)uit: ";
    cin >> option;
    option = tolower(option);

    //Reset stuff
    first_input = true; first = 0; second = 0;


    switch (option) {
      case 'l':
	first = float (input(error_char));
	second = float (input(error_char));
	break;
      case 'n':
	first = input(-100, 100, error_number);
	second = input(-100, 100, error_number);
	break;
      case 'p':
	break;
      case 'q':
	cout << "Good-bye!" << endl;
	break;
    }
  } while (option != 'q');
  return 0;
}

/*
Program Output:

*/
