// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 3  Purpose:  Virtual math tutor provides problems to challenge user.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

double getPercentage(int a, int b){
  if (b == 0)
    return -1;
  double percentage = double(a)/b;
  return percentage * 100;
}

int main(){
  //Welcome message
  cout << "Welcome to the virtual math tutor!" << endl
       << "This tutor will generate math problems to challenge you." << endl
       << "To stop the tutor, give any negative number as an answer." << endl
       << "Good luck!" << endl;
  
  //For decoding question_type into a string
  string decoder[4] = {"Multiplication","Division","Addition","Subtraction"};

  //Accumulators for the report card
  int qs_asked[4] = {0, 0, 0, 0};
  int qs_correct[4] = {0, 0, 0, 0};
  
  //Seed RNG
  srand(time(NULL));

  //Give problems
  bool done = false;
  while (!done){ 
    //Generate question type (*, /, +, or -)
    int question_type = rand() % 4;
    
    //Problem variables
    int a = 0;
    int b = 0;
    int c = 0;
    
    //Generate multiplication and division values
    if (question_type == 0 || question_type == 1){
      //Generate values
      c = rand() % 100 + 1;
      a = rand() % int(sqrt(c)) + 1;
      b = c / a;
      c = a * b;
    }
    
    //Generate add and subtract values
    if (question_type == 2 || question_type == 3){
      //Generate values
      c = rand() % 100 + 1;
      a = rand() % c + 1;
      b = c - a;
    }

    //Answer variables
    int user_answer = 0;
    int answer = 0;
    
    //Print appropriate question and record user_answer
    switch(question_type) {
      case 0 :
        printf("%d * %d = ", a, b);
        answer = c;
        cin >> user_answer;
        break;

      case 1 :
        printf("%d / %d = ",c, b);
        answer = a;
        cin >> user_answer;
        break;

      case 2 :
        printf("%d + %d = ", a, b);
        answer = c;
        cin >> user_answer;
        break;

      case 3 :
        printf("%d - %d = ", c, b);
        answer = a;
        cin >> user_answer;
        break;
    }

    //Update accumulators
    if (user_answer >= 0){
      ++qs_asked[question_type];
      if (user_answer == answer)
        ++qs_correct[question_type];
    }

    //Quit
    else {
      done = true;
      
    }
  }
  //Print report card
  cout << "\nYour Report Card:" << endl;
  for (int i = 0; i < 4; i++){
    int percentage = getPercentage(qs_correct[i], qs_asked[i]);
    if (percentage >= 0) {
      cout << decoder[i] << ":\t";
      printf("%d%% of %d question(s) correct. ", percentage, qs_asked[i]);
      if (percentage < 90)
        cout << "More study is recommended.";
      cout << endl;
    }
  }
  
  cout << "Goodbye!" << endl;
}

/*
Program output:
Welcome to the virtual math tutor!
This tutor will generate math problems to challenge you.
To stop the tutor, give any negative number as an answer.
Good luck!
71 - 62 = 9
16 / 4 = 4
1 * 98 = 98
96 / 16 = 6
10 / 5 = 2
3 * 4 = 12
3 * 4 = 12
64 - 53 = 11
91 + 7 = 98
15 - 6 = 9
11 + 35 = 46
13 + 7 = 20
37 - 25 = 12
30 / 10 = 3
80 / 80 = 1
2 * 15 = 30
35 - 12 = 2
4 * 16 = 2
13 + 24 = 2
7 * 10 = 2
30 / 10 = 2
4 * 5 = 2
1 * 15 = -1

Your Report Card:
Multiplication: 57% of 7 question(s) correct. More study is recommended.
Division:       83% of 6 question(s) correct. More study is recommended.
Addition:       75% of 4 question(s) correct. More study is recommended.
Subtraction:    80% of 5 question(s) correct. More study is recommended.
Goodbye!
*/
