
// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 3  Purpose:  Virtual math tutor provides problems to challenge user.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

int main(){
  //Welcome message
  cout << "Welcome to the virtual math tutor!" << endl
       << "This tutor will generate math problems to challenge you." << endl
       << "To stop the tutor, give any negative number as an answer." << endl
       << "Good luck!" << endl;

  //Some variables
  int user_answer;
  int answer;

  //Statistics
  int qs_asked[4] = {0, 0, 0, 0};
  int qs_correct[4] = {0, 0, 0, 0};

  //Seed RNG
  srand(time(NULL));

  //Give problems
  bool done = false;
  while (!done){ 
    //Generate question type (*, /, +, or -)
    int question_type = rand() % 4;

    int a = 0;
    int b = 0;
    int c = 0;
    
    //Generate multiplication and division
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

    //Quit tutor
    if (user_answer >= 0){
      ++qs_asked[question_type];
      if (user_answer == answer)
	++qs_correct[question_type];
    }

    //Update accumulators
    else {
      done = true;
      
    }
  }
  //Calculate score
  cout << "\nFinal Grades:" << endl;
  printf("Multiplication:\t%d/%d correct.\n", qs_correct[0], qs_asked[0]);
  printf("Division:\t%d/%d correct.\n", qs_correct[1], qs_asked[1]);
  printf("Addition:\t%d/%d correct.\n", qs_correct[2], qs_asked[2]);
  printf("Subtraction:\t%d/%d correct.\n", qs_correct[3], qs_asked[3]);

}
