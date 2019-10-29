/**********************************************************
 * Program name: Final - space header file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the header file for the 
 * space class. This is an abstract class. The children
 * classes are practiceRoom, studio, arena, and battle  
 * *******************************************************/

#include "guitarist.hpp"
#include <string>
using std::string;

#ifndef SPACE_HPP
#define SPACE_HPP

class space{
protected:
   space * top, * right, * left, * bottom;
   string name; 
public:
   space();
   space(string);
  
   space * getTop();
   void setTop(space*);
   space * getRight();
   space * getLeft();
   space * getBottom();
   void setBottom(space*);
   virtual void play(guitarist*){}
   virtual bool beatenBattle(){}
   string getName();
};


#endif

