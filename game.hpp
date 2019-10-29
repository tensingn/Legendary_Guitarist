/**********************************************************
 * Program name: Final - game header file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the header file for the games class.
 * This is where the game itself is controlled. The game
 * is created and the gameplay flows through the playGame
 * function. Lose game by running out of money. Win game
 * by beating all legend guitarists 
 * *******************************************************/

#include <list>
#include "space.hpp"
#include "guitarist.hpp"


#ifndef GAME_HPP
#define GAME_HPP

class game{
private:
   guitarist * me;
   std::list<guitarist*> bluesList, rockList, metalList, legendList;
   std::list<space*> world;
   space * location; //always start at practice
   space * p, * s, * a, * bBattle, * rBattle, * mBattle, * lBattle;

public:
   game();
   ~game();
   void playGame();
};

#endif
