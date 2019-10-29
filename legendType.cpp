/**********************************************************
 * Program name: Final - legendType imp file
 * Author: Nicholas Tensing
 * Date: 6/3/19
 * Description: This is the imp file for the 
 * legendType class. Their stats overall are much better
 * than everyone else.
 * *******************************************************/

#include "guitarist.hpp"
#include "legendType.hpp"
#include <string>
using std::string;


legendType::legendType() : guitarist(){
   type = "legend";
   speed = 85;
   riffing = 85;
   power = 85;
   emotion = 85;
   style = 85;
   minSkill = 50;
}

legendType::legendType(string name) : guitarist(name){
   type = "legend";
   speed = 85;
   riffing = 85;
   power = 85;
   emotion = 85;
   style = 85;
   minSkill = 50;
   this->name = name;
}
