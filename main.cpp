/**********************************************************
 * Program name: Final - main file
 * Author: Nicholas Tensing
 * Date: 6/3/19
 * Description: This is the main file for the Final Project.
 * This program is a guitar battle fantasy game. The user
 * creates their guitarist and they battle famous guitarists
 * from around the world. Once they have beaten enough 
 * guitarists, they enter the final level (legend level)
 * where they have the opportunity to battle guitar legends
 * and have their player become a lengend themselves.  
 * *******************************************************/

#include "game.hpp"
#include "valid.hpp"
#include "battle.hpp"
#include "arena.hpp"
#include "studio.hpp"
#include "practiceRoom.hpp"
#include "space.hpp"
#include "gear.hpp"
#include "legendType.hpp"
#include "bluesType.hpp"
#include "rockType.hpp"
#include "metalType.hpp"
#include "guitarist.hpp"
#include <ctime>
#include <cstdlib>
#include <list>
using std::list;
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main(){
   int seed = time(NULL);
   srand(seed);
      
   cout << "1. Play Game" << endl;
   cout << "2. Exit" << endl;
   while(valid(1,2) == 1){

      cout << "Welcome to the Legendary Guitarist Fantasy Game." << endl;
      cout << "You will start off as a new guitarists and work your" << endl;
      cout << "up to battle some of the world's most famous and " << endl;
      cout << "talented guitarists. There are 4 groups of guitarists to ";
      cout << "battle: " << endl;
      cout << "Blues Guitarists" <<endl;
      cout << "Rock Guitarists" << endl;
      cout << "Metal Guitarists" << endl;
      cout << "Legend Guitarists" << endl;
      cout << "The goal of the game is to defeat all the Legend Guitarists.";
      cout << endl;
      cout << "However, you will have no chance to beat them (their stats";
      cout << " are all super high) without going to the practice " << endl;
      cout << "room to get more consistent and beating the others " << endl;
      cout << "so you can win some of their gear to boost your ability." << endl;
      cout << " You lose the game by running out of money. " << endl;
      cout << "You must pay money to travel from space to space, " << endl;
      cout << "for living costs at the end of each day, to record " << endl;
      cout << "in the studio, practicing sessions, and lose some guitar battles. " << endl;
      cout << "There are ways to earn money back though. " << endl;
      cout << "The world is set up in a linear fasion going north/south";
      cout << endl;
      cout << "Northmost space: Legend Battle" << endl;
      cout << "Southermost space: Practice Room" << endl;
       cout << "Good luck and happy shredding! " << endl;
      game g;   
      g.playGame();
      cout << "1. Play again? " << endl;
      cout << "2. Exit" << endl;
   }

   return 0;
}
