/**********************************************************
 * Program name: Final - metalType implementation file
 * Author: Nicholas Tensing
 * Date: 6/3/19
 * Description: This is the implementation file for the 
 * metalType class.
 * *******************************************************/

#include "guitarist.hpp"
#include "metalType.hpp"
#include <string>
using std::string;


metalType::metalType() : guitarist(){
   type = "metal";
   speed = 80;
   riffing = 50;
   power = 70;
   emotion = 30;
   style = 20;
}

metalType::metalType(string name) : guitarist(name){
   type = "metal";
   speed = 80;
   riffing = 50;
   power = 70;
   emotion = 30;
   style = 20;
   this->name = name;
}
