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
    CoinPurse(int quarters=0, int dimes=0, int nickels=0, int pennies=0) {
      set(quarters, dimes, nickels, pennies);
    }
  
    int total_value() const {
      return _quarters*25 + _dimes*10 + _nickels*5 + _pennies*1;
    }
  
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
  
    string show() const {
      return "(q=" + to_string(_quarters) +
             " d=" + to_string(_dimes) +
             " n=" + to_string(_nickels) +
             " p=" + to_string(_pennies) + ")";
    }

  bool modify(int deltaQ, int deltaD, int deltaN, int deltaP) {
    return set(_quarters + deltaQ, _dimes + deltaD,
               _nickels + deltaN, _pennies + deltaP);
  }
  
};

void get_input(int&);

int main() {
  cout << "COSC 1337 Exam 2 CoinPurse" << endl;

  CoinPurse purse1 = CoinPurse(4, 3, 2, 1);
  cout << '$' << static_cast<double>(purse1.total_value())/100
       << endl;
  purse1.set(8, 7, 6, 5);
  cout << purse1.show() << endl;
  
  // Menu-Driven loop
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
      }
    }
  }

  // Step 12 EXTRA CREDIT) add c)ents option that allows the user to add a specific amount of cents
  
  cout<<endl<<"Goodbye!"<<endl; // this should appear as the last line of your output
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

*/

