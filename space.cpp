/**********************************************************
 * Program name: Final - space implementation file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the implementation file for the 
 * space class. This is an abstract class. The children
 * classes are practiceRoom, studio, arena, and battle  
 * *******************************************************/

#include "valid.hpp"
#include "space.hpp"
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//constructors
space::space(){
}

space::space(string name){
   top = NULL;
   right = NULL;
   bottom = NULL;
   left = NULL;
   this->name = name;
}


space * space::getTop(){
   return top;
}

void space::setTop(space * top){
   this->top = top;
}

space * space::getRight(){
   return right;
}

space * space::getLeft(){
   return left;
}

space * space::getBottom(){
   return bottom;
}

void space::setBottom(space * bottom){
   this->bottom = bottom;
}

string space::getName(){
   return name;
}

