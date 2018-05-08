/*
  Author:          Lee Reese
  Assignment:      Lab 11
  Topic:           memory diagram with stack, heap structures
  File Name:       TT17_L11_Reese.cpp
  Course/Section:  COSC 1337
  Due Date:        Tuesday 5/8
  Instructor:      Thayer
*/

#include<iostream>

using namespace std;

class Day{
  private:
    // Constants
    

    // Variables
    int _day;
  
  public:
    // Constants
    const static int daysInYear = 365;
    const static int year = 2018;
  
    // Constructor
    Day(int day=0) {
      // For nonexistant day, use 0 instead
      if (day < 0 || day > daysInYear)
        day = 0;
      _day = day;
    }

    // Return day
    int getDay() const {
      return _day;
    }


};

int main() {
  const static string monthsInYear[] = {"jan", "feb", "mar", "apr", "may", "jun",
                                      "jul", "aug", "sep", "oct", "nov", "dec"};
  const static int daysInMonth[] = {31, 28, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 31};
  return 0;
}
