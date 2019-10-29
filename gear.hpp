/**********************************************************
 * Program name: Final - gear header file
 * Author: Nicholas Tensing
 * Date: 6/4/19
 * Description: This is the header for the gear class. This
 * Each guitarist has guitar, amp, pedal, strap, and pick.
 * Certain gear gives certain stat boosts if the guitarist
 * has that item. 
 * *******************************************************/

#include <string>
using std::string;

#ifndef GEAR_HPP
#define GEAR_HPP

class gear{
protected: 
   int speed, riffing, power, emotion, style;
   string type, name;

public:
   gear();
   gear(string);
   gear(int,int,int,int,int,string,string);
   int getSpeed();
   void setSpeed(int);
   int getRiffing();
   void setRiffing(int);
   int getPower();
   void setPower(int);
   int getEmotion();
   void setEmotion(int);
   int getStyle();
   void setStyle(int);
   string getType();
   void setType(string);
   string getName();
   void setName(string);   
};



#endif




