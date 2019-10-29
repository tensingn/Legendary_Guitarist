/**********************************************************
 * Program name: Final - battle implementation file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the implementation file for the 
 * battle class. This is a child class of the space
 * class. This is where the user actually achieves
 * the objectives of the game. The user has a guitar
 * battle versus various guitarists of each region.
 * ***************************************************/

#include "gear.hpp"
#include "valid.hpp"
#include "battle.hpp"
#include "space.hpp"
#include "guitarist.hpp"
#include "gear.hpp"
#include <list>
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//constructors
battle::battle() : space(){

}

battle::battle(string name, list<guitarist*> g) : space(name){
   //valgrind says leak error here
   opp = g;
   
}

battle::~battle(){
   for(auto i = opp.begin(); i != opp.end(); ++i){
      delete *i;
      *i = NULL;
   } 
   for(auto i = defeat.begin(); i != defeat.end(); ++i){
      delete *i;
      *i = NULL;
   } 
}
   
//function where you actually have a guitar battle against
//the other guitarists. You battle one by one against the 
//list of guitarist for the particular battle region.
void battle::play(guitarist * g){
   //intro
   cout << endl;
   cout << "Prepare for a guitar battle! " << endl;
   cout << "If you win, you get to take your opponent's gear." << endl;
   cout << "If you lose, you will lose your non-generic gear. " << endl;
   cout << "If all your gear is generic, you will lose money." << endl;
   cout << endl;
   do{
   //who you need to beat
      cout << "Guitarists you need to still beat: " << endl;
      if(opp.empty()){
         //break if already beat everyone
         cout << "You have already beaten everyone here. " << endl;
         cout << "Exiting." << endl;
         break;
      }//who you need to bead
      for(auto i = opp.begin(); i != opp.end(); ++i){
         cout << (*i)->getName() << endl;
      }
      cout << endl;
      //who you have already beated
      cout << "Guitarists you have already beaten: " << endl;
      if(defeat.empty()){
         cout << "You haven't beaten anyone yet. " << endl;
      }
      for(auto i = defeat.begin(); i != defeat.end(); ++i){
         cout << (*i)->getName() << endl;
      } 
      cout << endl;
      //battle against first in list
      if(!opp.empty()){
         if(g->perform() > opp.front()->perform()){
            cout << "You beat " << opp.front()->getName() << endl;
    
            //win gear
            for(int i = 0; i < 5; i++){
               if(opp.front()->getGear(i)->getName() != "generic"){
                  cout << "Your prize is " << opp.front()->getGear(i)->getName();
                  cout << " " << opp.front()->getGear(i)->getType() << endl;
                  g->winGear(opp.front()->getGear(i),i);
                  
               }
            }
            //valgrind says leak error here
            defeat.push_back(opp.front());
            opp.pop_front();
         }else{
            cout << "You lost." << endl;
            
            //lose non-generic gear or pay money if all are generic
            if(g->getGear(0)->getName() == "generic" &&
               g->getGear(1)->getName() == "generic" &&
               g->getGear(2)->getName() == "generic" &&
               g->getGear(3)->getName() == "generic" &&
               g->getGear(4)->getName() == "generic"){
               //pay money if you have only generic gear
               cout << "All your gear is generic. You lose $1000." << endl;
               g->setBank(g->getBank() - 1000);
               cout << "You now have $" << g->getBank() << endl;
              
            }
            //lose gear
            else{
               for(int i = 0; i < 5; i++){
                  if(g->getGear(i)->getName() != "generic"){
                     cout << "You lost ";
                     cout << g->getGear(i)->getName() << " ";
                     cout << g->getGear(i)->getType() << endl;
                     g->loseGear(i);
                     i = 5;  //so we can exit the loop
                  }
               }
            }
         }
      }
      cout << endl;
      //determine whether you can battle anyone else
      if(opp.empty()){
         cout << "Looks like you have beaten everyone here. ";
         cout << "Exiting." << endl;
         break; 
      }else{
         if(g->getBank() <= 0){
            cout << "You have don't have enough money to battle." << endl;
            break;
         }else{
            //option to battle again 
            cout << "Another battle?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. Exit" << endl;
         }
      }
      
   }while(valid(1,2) == 1);
}

//returns true if you have beaten everyone in the battle region.
//only really used for the legend battle region because if you
//beat everyone there, you win the game
bool battle::beatenBattle(){
   if(opp.empty()){
      return true;
   }
}
