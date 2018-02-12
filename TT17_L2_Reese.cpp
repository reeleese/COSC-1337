

// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 2  Purpose:  Make diamonds.

#include <iostream>
using namespace std;

//Used because diamonds of an even height have an equal max width  to the diamond of odd height that precedes them. 
int prev_odd(int x){
  if (x % 2 == 0)
    return x-1;
  return x;
}

int main() {
  while (true){
    //Get diamond height.
    cout << "Enter the number of rows desired to make a diamond pattern. "
	 << "(0 to quit): ";
    int diamond_height = 0;
    cin >> diamond_height;
    
    //Quit if zero.
    if (diamond_height == 0)
      break;
    
    //The first half of each row is a substring of front.
    //Ex: if diamond_height == 5, then front = "  *****"
    string max_spaces = string ((diamond_height-1) / 2, ' ');
    string max_asterisks = string (prev_odd(diamond_height), '*');
    string front = "";
    front.append(max_spaces).append(max_asterisks);
    
    //The second half of each row is a substring of back.
    //Ex: If diamond_height == 5, then back = "*****  "
    string back = "";
    back.append(max_asterisks).append(max_spaces);
    
    //Calculate the size of the two substrings that comprise a row.
    int front_size = (diamond_height + 1) / 2;
    int back_size = prev_odd(diamond_height) / 2;
    
    //Make the diamond.
    for (int row = 0; row < diamond_height; row++){
      //Substring beginning indexes.
      int front_start = 0;
      int back_start = 0;
      
      //Bottom  half of diamond.
      if (row >= diamond_height/2){
	back_start = row;
	if (diamond_height % 2 != 0)
	  ++back_start;
	front_start = diamond_height -row -1;
      }

      //Top half of diamond. (up to and including the widest row(s))
      else {
	front_start = row;
	back_start = prev_odd(diamond_height) -row;
      }
      
      //Print row.
      cout << front.substr(front_start, front_size) 
	   << back.substr(back_start, back_size) 
	   << "\n";
    }
  }
  cout << "Goodbye!\n";
}
/*
Program Output:
Enter the number of rows desired to make a diamond pattern. (0 to quit): 1
*
Enter the number of rows desired to make a diamond pattern. (0 to quit): 2
*
*
Enter the number of rows desired to make a diamond pattern. (0 to quit): 3
 * 
***
 * 
Enter the number of rows desired to make a diamond pattern. (0 to quit): 4
 * 
***
***
 * 
Enter the number of rows desired to make a diamond pattern. (0 to quit): 5
  *  
 *** 
*****
 *** 
  *  
Enter the number of rows desired to make a diamond pattern. (0 to quit): 6
  *  
 *** 
*****
*****
 *** 
  *  
Enter the number of rows desired to make a diamond pattern. (0 to quit): 7
   *   
  ***  
 ***** 
*******
 ***** 
  ***  
   *   
Enter the number of rows desired to make a diamond pattern. (0 to quit): 8
   *   
  ***  
 ***** 
*******
*******
 ***** 
  ***  
   *   
Enter the number of rows desired to make a diamond pattern. (0 to quit): 9
    *    
   ***   
  *****  
 ******* 
*********
 ******* 
  *****  
   ***   
    *    
Enter the number of rows desired to make a diamond pattern. (0 to quit): 10
    *    
   ***   
  *****  
 ******* 
*********
*********
 ******* 
  *****  
   ***   
    *    
Enter the number of rows desired to make a diamond pattern. (0 to quit): 60
                             *                             
                            ***                            
                           *****                           
                          *******                          
                         *********                         
                        ***********                        
                       *************                       
                      ***************                      
                     *****************                     
                    *******************                    
                   *********************                   
                  ***********************                  
                 *************************                 
                ***************************                
               *****************************               
              *******************************              
             *********************************             
            ***********************************            
           *************************************           
          ***************************************          
         *****************************************         
        *******************************************        
       *********************************************       
      ***********************************************      
     *************************************************     
    ***************************************************    
   *****************************************************   
  *******************************************************  
 ********************************************************* 
***********************************************************
***********************************************************
 ********************************************************* 
  *******************************************************  
   *****************************************************   
    ***************************************************    
     *************************************************     
      ***********************************************      
       *********************************************       
        *******************************************        
         *****************************************         
          ***************************************          
           *************************************           
            ***********************************            
             *********************************             
              *******************************              
               *****************************               
                ***************************                
                 *************************                 
                  ***********************                  
                   *********************                   
                    *******************                    
                     *****************                     
                      ***************                      
                       *************                       
                        ***********                        
                         *********                         
                          *******                          
                           *****                           
                            ***                            
                             *                             
Enter the number of rows desired to make a diamond pattern. (0 to quit): 0
Goodbye!
*/
