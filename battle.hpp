/**********************************************************
 * Program name: Final - battle header file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the header file for the 
 * battle class. This is a child class of the space
 * class. This is where the user actually achieves
 * the objectives of the game. The user has a guitar
 * battle versus various guitarists of each region.
 * ***************************************************/

#include "space.hpp"
#include "guitarist.hpp"
#include <list>
using std::list;
#include <string>
using std::string;

#ifndef BATTLE_HPP
#define BATTLE_HPP

class battle : public space{
private:
   list<guitarist*> opp;      //not yet defeated
   list<guitarist*> defeat;   //already defeated
public:
   battle(); 
   battle(string);
   battle(string,list<guitarist*>);
   ~battle();
   void play(guitarist *);
   bool beatenBattle();
};



#endif
