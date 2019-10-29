/**********************************************************
 * Program name: Final - bluesType imp file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: Imp file for the bluesType class. This
 * is a child of the guitarist class.
 * *******************************************************/

#include "guitarist.hpp"
#include "bluesType.hpp"
#include <string>
using std::string;


bluesType::bluesType() : guitarist(){
   type = "blues";
   speed = 20;
   riffing = 70;
   power = 30;
   emotion = 90;
   style = 40;
}

bluesType::bluesType(string name) : guitarist(name){
   type = "blues";
   speed = 20;
   riffing = 70;
   power = 30;
   emotion = 90;
   style = 40;
   this->name = name;
}
