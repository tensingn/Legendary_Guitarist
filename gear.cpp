/**********************************************************
 * Program name: Final - gear imp file
 * Author: Nicholas Tensing
 * Date: 6/4/19
 * Description: This is the imp for the gear class. This
 * Each guitarist has guitar, amp, pedal, strap, and pick.
 * Certain gear gives certain stat boosts if the guitarist
 * has that item. 
 * *******************************************************/

#include "gear.hpp"
#include <string>
using std::string;

gear::gear(){
   speed = 0;
   riffing = 0;
   power = 0;
   emotion = 0;
   style = 0;
}

//constructor for basic gear that doesn't improve any stats
gear::gear(string t){
   speed = 0;
   riffing = 0;
   power = 0;
   emotion = 0;
   style = 0;
   name = "generic";
   type = t;
   
}

//constructor for special gear that you win from beating other
//guitarists. These improve stats
gear::gear(int sp, int r, int p, int e, int st, string t, string n){
   speed = sp;
   riffing = r;
   power = p;
   emotion = e;
   style = st;
   type = t;
   name = n;
}

int gear::getSpeed(){
   return speed;
}

void gear::setSpeed(int speed){
   this->speed = speed;
}

int gear::getRiffing(){
   return riffing;
}

void gear::setRiffing(int riffing){
   this->riffing = riffing;
}

int gear::getPower(){
   return power;
}

void gear::setPower(int power){
   this->power = power;
}

int gear::getEmotion(){
   return emotion;
}

void gear::setEmotion(int emotion){
   this->emotion = emotion;
}

int gear::getStyle(){
   return style;   
}

void gear::setStyle(int style){
   this->style = style;
}

string gear::getType(){
   return type;
}

void gear::setType(string type){
   this->type = type;
}

string gear::getName(){
   return name;
}

void gear::setName(string name){
   this->name = name;   
}



