/**********************************************************
 * Program name: Final - validation implementation file
 * Author: Nicholas Tensing
 * Date: 6/9/19
 * Description: This is the implementaiton file for the
 * validation function. The function takes 2 integers as
 * parameters. Oneint is the min and the other is the max.
 * The function validates that the input is an integer and
 * if it is an integer, the function validates that it is
 * in range. 
 * *******************************************************/

#include "valid.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int valid(int min, int max){
   int choice = min-1;//so choice always starts out of range
   cout << "Please enter an integer from " << min << " to " << max << endl;
   cin >> choice;
   while(choice < min || choice > max || cin.fail()){
      cout << "Please enter an integer from " << min << " to " << max << endl;
      if(cin.fail()){
         cin.clear();
         cin.ignore(32767,'\n');
      }
      else{
         cin.ignore(32767,'\n');
      }
      cin >> choice;
   }
   cin.ignore(72767,'\n');  
   return choice;
}
