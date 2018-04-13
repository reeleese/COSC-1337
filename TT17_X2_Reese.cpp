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
    CoinPurse(int quarters=0, int dimes=0, int nickels=0, int pennies=0) {
      
      // Step 6) avoid redundant code, call set() in constructor(s)
      set(quarters, dimes, nickels, pennies);
    }
  
    // Step 3) Write total_value to return total value of coins in CoinPurse object
    int total_value() const {
      return _quarters*25 + _dimes*10 + _nickels*5 + _pennies*1;
    }

    // Step 5) Implement set() which modifies the coin counts
    bool set(int quarters, int dimes, int nickels, int pennies) {
      // If any values are negative, do nothing
      if (quarters < 0 || dimes < 0 || nickels < 0 || pennies < 0)
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
    string show() const {
      return "(q=" + to_string(_quarters) +
             " d=" + to_string(_dimes) +
             " n=" + to_string(_nickels) +
             " p=" + to_string(_pennies) + ")";
    }
  
    // Step 9) write modify() method to modify coin counts using a positive (increment),
    // negative (decrement) or zero (keep the same) value.
    bool modify(int deltaQ, int deltaD, int deltaN, int deltaP) {
      return set(_quarters + deltaQ, _dimes + deltaD,
                 _nickels + deltaN, _pennies + deltaP);
  }
  
};

void get_input(int&);

int main() {
  cout << "COSC 1337 Exam 2 CoinPurse" << endl;

  // Step 2) declare CoinPurse object called purse1;
  // initialize with: 4 quarters, 3 dimes, 2 nickels, 1 penny
  CoinPurse purse1 = CoinPurse(4, 3, 2, 1);

  // Step 4) Call the total_value method on purse1; display the result formatted as: $x.xx
  cout << '$' << static_cast<double>(purse1.total_value())/100
       << endl;

  // Step 8) Call set to change values in purse1 to: 8 quarters, 7 dimes, 6 nickels, 5 pennies.
  // Call show to display the contents of purse1
  purse1.set(8, 7, 6, 5);
  cout << purse1.show() << endl;
  
  // Step 10) write menu driven loop that allows the user the add or remove coins from purse1.
  bool done = false;
  while(!done) {
    // Display Menu and current sataus of purse1
    cout << setprecision(2) << fixed
         << '$' << static_cast<double>(purse1.total_value())/100
         << " " << purse1.show() << " "
         << "Modify p)enny n)ickel d)ime q)uarter s)top: ";

    // Get user option
    char choice = cin.get(); 

    // Only get modify values if user chooses not to quit
    if (choice == 's')
      done = true;
    else {
      // Get delta
      cin.ignore(255, ' ');
      int delta; get_input(delta);
    
      // Modify appropriate coins by delta
      const string error_message = "You may not have fewer than 0 of any coin!";
      switch (choice) {
        case 'q' : { //quarters
          if(!purse1.modify(delta, 0, 0, 0))
            cout << endl << error_message << endl;
          break;
        }

        case 'd' : { //dimes
          if(!purse1.modify(0, delta, 0, 0))
            cout << endl << error_message << endl;
         break;
        }

        case 'n' : { //nickels
          if(!purse1.modify(0, 0, delta, 0))
            cout << endl <<error_message << endl;
          break;
       }

       case 'p' : { //pennies
         if(!purse1.modify(0, 0, 0, delta))
            cout << endl << error_message << endl;
          break;
        }
	 
        // Step 12 EXTRA CREDIT) add c)ents option that allows the user to add a specific amount of cents
        case 'c' : { //cents
          int cents = delta;

          // Get required no. of each coin type
          int quarters = cents / 25;
            cents %= 25;
          int dimes = cents / 10;
          cents %= 10;
          int nickels = cents / 5;
          cents %= 5;
          int pennies = cents;

          //Call a modify as we normally would
         if(!purse1.modify(quarters, dimes, nickels, pennies))
            cout << endl <<error_message << endl;
         break;
         }

        default : {
          cout << "Invalid option.";
        }
      } //end of switch
    } //end of if-else
  } // end of menu

    
  cout<<endl<<"Goodbye!"<<endl;
  return EXIT_SUCCESS; // Use return 0 if EXIT_SUCCESS is undefined
}

  void get_input(int& option) {  
  while (!(cin >> option)) {
    cin.clear();
    cout << "Value must be an integer.";
  }
  cin.ignore(255, '\n');
}

/*  Step 11) Paste test output here (do this after step 12 if doing extra credit)
COSC 1337 Exam 2 CoinPurse
$1.41
(q=8 d=7 n=6 p=5)
$3.05 (q=8 d=7 n=6 p=5) Modify p)enny n)ickel d)ime q)uarter s)top: p -3
$3.02 (q=8 d=7 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: n 0
$3.02 (q=8 d=7 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: d 2
$3.22 (q=8 d=9 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: q -4
$2.22 (q=4 d=9 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: d -6
$1.62 (q=4 d=3 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: n -4
$1.42 (q=4 d=3 n=2 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: p -1
$1.41 (q=4 d=3 n=2 p=1) Modify p)enny n)ickel d)ime q)uarter s)top: c 125
$2.66 (q=9 d=3 n=2 p=1) Modify p)enny n)ickel d)ime q)uarter s)top: c 24
$2.90 (q=9 d=5 n=2 p=5) Modify p)enny n)ickel d)ime q)uarter s)top: s

Goodbye!
*/

