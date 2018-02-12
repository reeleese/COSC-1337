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
  int question_type;
  int answer;
  int a;
  int b;
  int user_answer;

  //seed
  srand(time(NULL));
  //Give problems
  bool done = false;
  while (!done){ 
    //Generate question type (*,/,+, or -) and answer
    question_type = rand() % 4;
    
    question_type = 0;
    //Multiplication
    if (question_type == 0 || question_type == 1){
      //Generate values
      answer = rand() % 100 + 1;
      a = rand() % int(sqrt(answer)) + 1;
      b = answer / a;
      answer = a * b;
      printf("a:%d b:%d answer:%d\n", a, b, answer);

      //Deliver problem
      printf("%d * %d = ", a, b);
      cin >> user_answer;
    }
    
    //question_type = 2;
    //Addition
    if (question_type == 2 || question_type == 3){
      //Generate values
      answer = rand() % 100 + 1;
      a = rand() % answer + 1;
      b = answer - a;
      
      //Deliver problem
      printf("%d + %d = ", a, b);
      cin >> user_answer;
    }

    if (user_answer < 0){
      done = true;
    } else if (user_answer == answer) {
      //Do something
    } else {
      //Do something else
    }
  }
  //calculate score
  return 0;
}
