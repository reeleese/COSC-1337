// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 6  Purpose: Calculate the distance between two things

/*
TODO:
-Purpose
-Program output

*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

//Variables
float distance;
auto first;
auto second;

//Error Messages
const string error_char = "";
const string error_number = "";
const string error_point = "";

//Prompts
const string prompt_char = "";
const string prompt_number = "";
const string prompt_point = ""

//Input Functions
char input(string prompt, string error_message) {
  cout << prompt << endl;

  cout << "Letter 1: ";
  cin >> first;
  
  cout << "Letter 2: ";
  cin >> second;

  if (!(isalpha(letter_first) && isalpha(letter_second))) {
    cout << error_message << endl;
    input(prompt, error_message);
  }

  cout << int(first) << " : " << int(second);
  distance = int(letter_first) - int(letter_second);
}

float input(float min, float max, string prompt, string error_message);
void input(double &x, double &y, string prompt);

//Distance functions

//Display functions


int main() {
  cout << "Choose a thing" << endl;
  
  cout << input("prompt", "error message");
  
  return 0;
}

/*
Program Output:

*/
