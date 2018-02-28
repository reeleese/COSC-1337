// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 6  Purpose: Calculate the distance between two things

/*
TODO:
-Program output
*/

#include <iostream>
#include <cmath>
using namespace std;

//Error Messages
const string error_char = "  Sorry, character must be alphabetic. Try again.";
const string error_number = "  Sorry, out-of-range. Try again.";
const string error_point = "  This error should never happen.";

//Input Functions
char input(string prompt, string error_message);
float input(string prompt, float min, float max, string error_message);
void input(string prompt, double &x, double &y, string error_message);
void point_input_helper(string prompt, double &destination, char axis,
			string error_message);
//Distance functions
int dist(char a, char b);
float dist(float a, float b);
float dist(double x1, double y1, double x2, double y2);

//Display functions
void display(string msg, char ch1, char ch2, int d);
void display(string msg, float f1, float f2, float d);
void display(string msg, double x1, double y1, double x2, double y2, double d);

int main() {
  //Display program purpose
  cout << "Display the distance between two items: letters numbers, or points."
       << "\n\n";

  //Menu
  char option{};
  do {
    cout << "Options: l)etter; n)umber; p)oint; q)uit: ";
    cin >> option;
    option = tolower(option);
    
    //letter
    if (option == 'l') {
      char char1 = input("Enter the first letter (a to z): ", error_char);
      char char2 = input("Enter the second letter (a to z): ", error_char);
      int distance = dist(char1, char2);
      display("Distance between letters", char1, char2, distance);
    }
    //number
    else if (option == 'n') {
      float num1 = input("Enter the first number", -100, 100, error_number);
      float num2 = input("Enter the next number", -100, 100, error_number);
      float distance = dist(num1, num2);
      display("Units between", num1, num2, distance);
    }
    //point
    else if (option == 'p') {
      double x1; double y1;
      input("Enter the first point", x1, y1, error_point);
      double x2; double y2;
      input("Enter the second point", x2, y2, error_point);
      double distance = dist(x1, y1, x2, y2);
      display("Straight line distance between", x1, y1, x2, y2, distance);
    }
    //quit
    else if (option == 'q')
      cout << "Good-bye!";
    //Bad input
    else
      cout << "Invalid option choice." << endl;
    
    cout << "\n\n";
  } while (option != 'q');
  return 0;
}

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
  if (user_input < min ||  user_input > max) {
    cout << error_message << endl;
    return input(prompt, min, max, error_message);
  }

  return user_input;
}

void input(string prompt, double &x, double &y, string error_message) {  
  point_input_helper(prompt, x, 'x', error_message);
  point_input_helper(prompt, y, 'y', error_message);
}
void point_input_helper(string prompt, double &destination, char axis,
			string error_message) {
  cout <<  prompt << " (" << axis << "): ";
  
  while (!(cin >> destination)) {
    cout << error_message << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << prompt << " (" << axis << "): ";
  }
}
/*-----Distance Functions-----*/
//letter
int dist(char a, char b) {
  int a_num = int (tolower(a));
  int b_num = int (tolower(b));
  return abs(a_num - b_num);
}
//number
float dist(float a, float b) {
  return abs(a - b);
}
//point
float dist(double x1, double y1, double x2, double y2) {
  double a_squared = pow(x2-x1, 2);
  double b_squared = pow(y2-y1, 2);
  return sqrt(a_squared + b_squared);

}


void display(string msg, char ch1, char ch2, int d){
  static int count = 1;
  cout << "(#" << count << ") "
       << msg << " " << ch1 << " & " << ch2 << " = "
       << d;
  ++count;
}
void display(string msg, float f1, float f2, float d){
  static int count = 1;
  cout << "(#" << count << ") "
       << msg << " " << f1 << " and " << f2 << " = "
       << d;
  ++count;
}
void display(string msg, double x1, double y1, double x2, double y2, double d){
  static int count = 1;
  cout << "(#" << count << ") "
       << msg << " " 
       << "(" << x1 << ", " << y1 << ") and " 
       <<  "(" << x2 << ", " << y2 << ") is: "
       << d;
  ++count;
}


/*
Program Output:

*/
