/**********************************************************
 * Program name: Final - guitarist header file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the head file for the guitarist 
 * class. There are a few different types of 
 * guitarist, which are based on genres of music. The 
 * types are children classes of the guitarist class.
 * *******************************************************/

//#include "space.hpp"
#include "gear.hpp"
#include <string>
using std::string;

#ifndef GUITARIST_HPP
#define GUITARIST_HPP

class guitarist{
protected:
   int speed, riffing, power, emotion, style, bank, minSkill;
   string name, type;
   gear * rig[5]; //your rig
  // space * location;
public:
   guitarist();
   guitarist(string);
   ~guitarist();
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
   int getBank();
   void setBank(int);
   int getMinSkill();
   void setMinSkill(int);
   void getStats();
   string getName();
   void setName(string);
   string getType();
   int perform();
   //rig
   gear * getGear(int);
   void winGear(gear *, int); //basically setPick
   void loseGear(int);
   void getRig();
  // space * getLocation();
 //  void setLocation(space *);
};

#endif



