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
float first;
float second;


//Error Messages
const string error_char = "  Sorry, character must be alphabetic. Try again.";
const string error_number = "Sorry, out-of-range. Try again.";
const string error_point = "This error should never happen.";

//Prompts
const string prompt_char = "Gimme a character: ";
const string prompt_number = "Gimme a number";
const string prompt_point = "";

//Input Functions
char input(string prompt, string error_message) {
  //Prompt
  cout << prompt;
  
  //Input
  char user_input{};
  cin >> user_input;
  
  //If char is not a-z or A-Z, try again.
  if (!isalpha(user_input)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << error_message << endl;
    return input(prompt, error_message);
  }
  return user_input;
}

float input(string prompt, float min, float max, string error_message) {
  //Prompt
  cout << prompt
       << " (" << min << ", " << max << "): ";
  
  //Get Number
  float user_input{};
  cin >> user_input;

  //If user is not in range, try again.
  if (!(min <= user_input <= max)) {
    cout << error_message << endl;
    return input(prompt, min, max, error_message);
  }

  return user_input;
}
/*
void input(string prompt, double &x, double &y, string error_message) {  
  //Input
  string user_x{};
  do {
    cout << "Enter the "<< iteration << " point (x): ";
    
  } while (!(cin >> x));

  cout << "Enter the " << iteration << " point (y): ";
  cin >> y;
}*/

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
void display(string msg, char ch1, char ch2, int d){
  static int count = 1;
  cout << "(#" << count << ") "
       << msg << " " << ch1 << " and " << ch2 << " = "
       << d;
  ++count;
}
void display(string msg, float f1, float f2, float d){
  static int count = 1;
  cout << "(#" << count << ") "
       << "Units between " << f1 << " and " << f2 << " = "
       << d;
  ++count;
}
void display(string msg, double x1, double y1, double x2, double y2, double d){
  static int count = 1;
  cout << "(#" << count << ") "
       << "Straight line distance between " 
       << "(" << x1 << ", " << y1 << ") and " 
       <<  "(" << x2 << ", " << y2 << ") is: "
       << d;
  ++count;
}

int main() {
  //Display program purpose
  cout << "Display the distance between two items: letters numbers, or points."
       << "\n\n";

  //Sentinel
  char option{};
  
  //Menu
  do {
    //Prompt
    cout << "Options: l)etter; n)umber; p)oint; q)uit: ";
    cin >> option;
    option = tolower(option);

    if (option == 'l') {
      char char1 = input("Enter the first letter (a to z): ", error_char);
      char char2 = input("Enter the second letter (a to z): ", error_char);
      int distance = dist(char1, char2);
      display("Distance between letters", char1, char2, distance);
    }
    else if (option == 'n') {
      float num1 = input("Enter the first number", -100, 100, error_number);
      float num2 = input("Enter the next number", -100, 100, error_number);
      float distance = dist(num1, num2);
      display("Units between", num1, num2, distance);
    }
    else if (option == 'q') {
      cout << "Good-bye!" << endl;
    }

    else {
      cout << "Invalid option choice." << endl;
    } 
    
    cout << "\n\n";
  } while (option != 'q');
  return 0;
}

/*
Program Output:

*/
