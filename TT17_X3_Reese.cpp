/*
  COSC 1337 Exam 3 Lab portion Spring 2018
  Name:     Lee Reese
  Filename: TT17_X3_Reese.cpp
    before submitting, change the file name
      from: DDHH_X3_Lastname.cpp
      to:   <your course designator>_X3_<your last name>.cpp
      where DDHH is the days, hours your course meets (example: TT13)
      -or-  DDHH is the distance learning section (example: DL5)
      
    NOTE: In devcpp, compiler options (Tools -> Compiler Options) must have: -std=c++11
    otherwise, you may get this error:
    [Warning] extended initializer lists only available with -std=c++11 or -std=gnu++11 
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// ----------------------------------------------
// The section below is provided startup code for step 1.
// DO NOT CHANGE UNLESS COMPLIER ERROR.
// Below, a std::vector is used. It works as-is.
// It creates an vector (array) as described in the instructions. It provides
// intial startup data for you to save time.
// Use this data to load your store with items.
struct T {string name; double price; string made_in; int weight;};
vector<T> stuff {
  {"hat", 8.00, "china", 6},
  {"t-shirt", 15.00, "usa", 14},
  {"coffee mug", 6.50, "canada", 22},
  {"candy bar", 0.79, "mexico", 3},
  {"", 34.59, "japan", 122},
  {"mixing bowl", 4.99, "brazil", 20}
};

void show_stuff() { // verify that stuff contains the data as specified.
  cout<<"Contents of vector stuff, already loaded:\n";
  for (auto &t:stuff) { // If this does not compile, see the note below
    cout<<setw(12)<<right<<t.name<<setw(8)<<t.price<<setw(8)<<t.made_in<<setw(6)<<t.weight<<endl;
  }
  cout<<endl;
}
// If the for (auto &t:stuff) code has a compilation error, you can do this:
//   1) recommended:
//      enable C++11/14 features on your compiler with option: -std=c++11
//   2) alternative:
//      change to a regular for loop: for (int i=0; i<stuff.length(); ++i), etc.
// The section above is provided startup code.
// DO NOT CHANGE UNLESS COMPILER ERROR
// ----------------------------------------------

// Put class Item definition code for steps 1 and 2 here.
class Item {
  private:
    // 1A: member variables
    string name;
    float price;
  public:
    // 1C: Constructor
    Item(string name= "item", float price= 1.00) {
      if (name.size() < 1 || price < 1) {
        name = "invalid";
        price = 1;
    }
      this->name = name;
      this->price = price;
    }

    // 1B: Display name and price
    void display() const {
      cout << setw(12) << right << name << " "
           << "$ " << setprecision(2) << fixed << price;
   }
};


void step1() {
  cout<<"Step 1:\n";
  show_stuff();
  // Provided startup code to demonstrate that
  // stuff contains initial startup data.
  // Put testing code for step 1 here:

  // 1D: Array of Items
  const int size = stuff.size();
  Item store[size];
  for (int i = 0; i < size; i++)
    store[i] = Item(stuff[i].name, stuff[i].price);

  // 1E: Loop display
  cout << "Contents of store, as loaded by student's new code:\n";
  for (int i = 0; i < size; i++) {
    store[i].display();
    cout << '\n';
  }
  // END OF PART 1
  cout << endl;
}

void step2() {
  cout<<"Step 2:\n";
  // Put all your code for step 2 here:

  // 2A:
  Item* part2 = new Item("black umbrella", 19.95);

  // 2B:
  cout << "umbrella is at address: " << part2 << endl;

  // 2C:
  part2->display();
  cout << endl;

  // 2D:
  delete part2;
  part2 = nullptr;

  // END OF PART 2
  cout << endl;
}

// Step 3: The initial code for class Fraction is provided.
//         You will add to it further down...
class Fraction {
  // A fraction is a number that can be written as:
  // numerator/denominator, such as: 1/2, 5/1, etc.
  private:
    int numerator=0;
    int denominator=1;
  public:
    Fraction(int numerator=0, int denominator=1) {
      if (denominator != 0) { // guard against division by 0
        this->numerator = numerator;
        this->denominator = denominator;
      }
    }
    double get() const {
      return numerator/denominator;
    }
    
    // Put new code for step 3 here:

    // 3A;
    Fraction operator++() {
      this->numerator++;
      return *this;
    }

    // 3B:
    Fraction operator--() {
      this->numerator--;
      return *this;
    }

    // 3C:
    Fraction operator*(Fraction arg) {
      Fraction temp;
      temp.numerator = numerator * arg.numerator;
      temp.denominator = denominator * arg.denominator;
      return temp;
    }
};
  
void step3() {
  cout<<"Step 3:\n";
  // This is testing code for step 3.
  // After you have implemented: operator++, operator--, and operator*,
  // Uncomment the code below. It should work.
  Fraction a=4; ++a; ++a; cout<<"a="<<setprecision(0)<<a.get()<<endl;
  // test code, expect: 6, uncomment when ready
     Fraction b=5; --b; --b; cout<<"b="<<b.get()<<endl;
  // test code, expect: 3, uncomment when ready
     Fraction c=6, d=7, e=c*d;
  // test code, uncomment when ready
     cout<<"e="<<e.get()<<endl<<endl;
  // test code, expect: 42, uncomment when ready
  // add code here to initialize Fraction evens[]
  // with 2 4 6 8 10 and display its contents

  // 3D: 
  Fraction evens[] = {2, 4, 6, 8, 10};
  for (auto& x : evens)
    cout << x.get() << " ";

  // END OF STEP 3
  cout << endl;
};

// The code below is for step 4, recursion
// This startup code may be helpful when developing your recursive functions.
void recurse(int times_to_call) {
  // a generalized recursion outline; has 5 locations to do work...
  cout << "recurse head... " << "("<<times_to_call<<") " <<endl;
  if (times_to_call>1) {
    cout << "recurse before call... " << "("<<times_to_call<<") " <<endl;
    recurse(times_to_call-1); // work can also be done inside the parameter list
    cout << "recurse after call... " << "("<<times_to_call<<") " <<endl;
  } else {
    cout << "recurse else option... " << "("<<times_to_call<<") " <<endl;
  }
  cout << "recurse ...tail " << "("<<times_to_call<<") " <<endl;
}

// Below are working iterative versions of line,
// left_arrow, right_arrrow, double_arrow
void line_iterative(int n) { // Provided, do not change
  for (int i=0; i<n; ++i)
    cout<<"-";
}

void left_arrow_iterative(int n) { // Provided, do not change
  cout<<"<";
  for (int i=0; i<n; ++i)
    cout<<"-";
}

void right_arrow_iterative(int n) { // Provided, do not change
  for (int i=0; i<n; ++i)
    cout<<"-";
  cout<<">";
}

void double_arrow_iterative(int n) { // Provided, do not change
  cout<<"<";
  for (int i=0; i<n; ++i)
    cout<<"-";
  cout<<">";
}

// Put your new recursive versions for step 4 here...
void line(int n) {
   // fill this in with recursive code for line
  if (n > 1) line(n-1);
  cout << '-';
}

void left_arrow(int n) {
  // fill this in with recursive code for left_arrow
  if (n <= 0) cout << '<';
  else {left_arrow(n-1); cout << '-';}
}

void right_arrow(int n) {
  // fill this in with recursive code for right_arrow
  if (n > 0) {cout << '-'; right_arrow(n-1);}
  else cout << '>';
  
}

void double_arrow(int n, bool head) {
  // This one is a challenge. Hint: add another parameter
  // fill this in with recursive code for double_arrow
  if (head) cout << '<';
  if (n > 0) {cout << '-'; double_arrow(n-1, false);}
  else cout << '>';
}

void step4() {
  // Below is testing code for step 4. No changes needed.
  // recurse(3); // call to recurse example for experimentation, if desired
  cout<<"\nStep 4:\n";
  cout<<"Test provided iterative versions of line, left_arrow, right_arrow, double_arrow:\n";
  for (int n=1; n<=5; ++n) { // test provided iterative functions
    cout<<"n="<<setw(2)<<n<<":";
    line_iterative(n); cout<<' ';
    left_arrow_iterative(n); cout<<' ';
    right_arrow_iterative(n); cout<<' ';
    double_arrow_iterative(n); cout<<endl;
  }
  cout<<"\nTest student's new recursive versions of line, left_arrow, right_arrow, double_arrow:\n";
  for (int n=1; n<=5; ++n) { // test student's new recursive functions
    cout<<"n="<<setw(2)<<n<<":";
    line(n); cout<<' ';
    left_arrow(n); cout<<' ';
    right_arrow(n); cout<<' ';
    double_arrow(n, true); cout<<' '<<endl;
  }
  cout << endl;
};

void step5() {
  // 5 different ways to cause undefined behavior,
  // and possibly crash a C++ program.
  // in main, step5() is commented out.
  // To verify your bad code is really bad,
  // test it by uncommenting step5() in main.
  cout<<"Step 5:\n";
  // Put all your code for step 5 here:

  // Bad thing 1: Array access out-of-bounds
  int evil[] = {666};
  cout << "evil[1] = " << evil[1] << endl;;

  // Bad thing 2: Dereference an allocation of size 0
  int *satan = new int[0];
  cout << "*satan = " << *satan << endl;
  delete[] satan;

  // Bad thing 3: using a pointer whose allocation has been deleted
  cout << "*satan = " << *satan << endl;

  // Bad thing 4: integer overflow
  unsigned int x = 0;
  x--;
  cout << "Value of x: " << x << endl;

  // Bed thing 5: doing arithmetic with a variable that has not been assigned
  int i; i++;
  cout << "i = " << i << endl;

};

int main() {
  // No new code goes in main. Put all new code where designated in the steps above.
  cout<<"Start...\n";
  step1();
  step2();
  step3();
  step4();
   step5(); // Extra credit: 5 ways to possibly crash a C++ program
  cout<<"\n...end.\n";
	return 0;
}

/* Original startup code test output:
Start...
Step 1:
Contents of vector stuff, already loaded:
         hat       8   china     6
     t-shirt      15     usa    14
  coffee mug     6.5  canada    22
   candy bar    0.79  mexico     3
               34.59   japan   122
 mixing bowl    4.99  brazil    20

Step 2:
Step 3:

Step 4:
Test provided iterative versions of line, left_arrow, right_arrow, double_arrow:
n= 1:- <- -> <->
n= 2:-- <-- --> <-->
n= 3:--- <--- ---> <--->
n= 4:---- <---- ----> <---->
n= 5:----- <----- -----> <----->

Test student's new recursive versions of line, left_arrow, right_arrow, double_arrow:
n= 1:
n= 2:
n= 3:
n= 4:
n= 5:

...end.
*/


/* Paste your test output here:

*/
