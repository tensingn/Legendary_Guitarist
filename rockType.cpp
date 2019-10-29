/**********************************************************
 * Program name: Final - rockType header file
 * Author: Nicholas Tensing
 * Date: 6/3/19
 * Description: This is the header file for the 
 * rockType class.
 * *******************************************************/

#include "guitarist.hpp"
#include "rockType.hpp"
#include <string>
using std::string;


rockType::rockType() : guitarist(){
   type = "rock";
   speed = 60;
   riffing = 50;
   power = 50;
   emotion = 40;
   style = 50;
}

rockType::rockType(string name) : guitarist(name){
   type = "rock";
   speed = 60;
   riffing = 50;
   power = 50;
   emotion = 40;
   style = 50;
   this->name = name;
}
