/*
  Name: Lee Reese
  COSC 1337 Spring 2018 TT17
  Exam 2, Programming portion
  When complete: Change course designator in filename from DDHH to TT17
                 Change "Lastname" to your lastname.
  Upload file: TT17_X2_Lastname.cpp to BlackBoard Assignment link.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class CoinPurse
{
  private:
    int _quarters, _dimes, _nickels, _pennies;
  public:
  //  Step 1) Write two CoinPurse constructors:
  //    default: set all coin counts to zero
  //    2nd:     set all coin counts to initial values; use parameters for: penny, nickel, dime, quarter
  //    please combine both of these into one constructor
  
  // Step 6) avoid redundant code, call set() in constructor(s)

  CoinPurse(int quarters = 0, int dimes = 0, int nickels = 0, int pennies = 0) {
    set(quarters, nickels, dimes, pennies);
  }
  
  // Step 3) Write total_value to return total value of coins in CoinPurse object
  int total_value() const; // return total cents as int // getters should be marked as const
  
  bool set(int quarters, int dimes, int nickels, int pennies) {
    // If any values are negative, do nothing
    if (quarters <= 0 || dimes <= 0 || nickels <= 0 || pennies <= 0)
      return false;

    // Assign values iff given values are valid
    _quarters = quarters;
    _dimes = dimes;
    _nickels = nickels;
    _pennies = pennies;
    return true;
  }
  
  // Step 7) write show() method that outputs the number of each coin in the purse
  //  in one string, like this: "q=4 d=3 n=2 p=1" (don't << endl;)
  void show() const;

  // Step 9) write modify() method to modify coin counts using a positive (increment),
  // negative (decrement) or zero (keep the same) value.
  bool modify(int, int, int, int);
  
};

int main() {
  cout << "COSC 1337 Exam 2 CoinPurse" << endl;

  // Step 2) declare CoinPurse object called purse1;
  // initialize with: 4 quarters, 3 dimes, 2 nickels, 1 penny

  // Step 4) Call the total_value method on purse1; display the result formatted as: $x.xx

  // Step 8) Call set to change values in purse1 to: 8 quarters, 7 dimes, 6 nickels, 5 pennies.
  //         Call show to display the contents of purse1

  // Step 10) write menu driven loop that allows the user the add or remove coins from purse1.

  // Step 12 EXTRA CREDIT) add c)ents option that allows the user to add a specific amount of cents
  
  cout<<endl<<"Goodbye!"<<endl; // this should appear as the last line of your output
  return EXIT_SUCCESS; // Use return 0 if EXIT_SUCCESS is undefined
}


/*  Step 11) Paste test output here (do this after step 12 if doing extra credit)

*/

