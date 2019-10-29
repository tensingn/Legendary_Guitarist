/**********************************************************
 * Program name: Final - game imp file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the imp file for the games class.
 * This is where the game itself is controlled. The game
 * is created and the gameplay flows through the playGame
 * function. Lose game by running out of money. Win game
 * by beating all the legend guitarists 
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


//constructor to set up game
game::game(){
//set up user character based on user input
   string name;
   cout << "Name your guitarist." << endl;
   cin >> name;
   cout << endl;
   cout << "Select what type of guitarist your player will be." << endl;
   cout << "1. Blues guitarist" << endl;
   cout << "2. Rock guitarist" << endl;
   cout << "3. Metal guitarist" << endl;
   cout << endl;
   int choice = valid(1,3);
   if(choice == 1){
      me = new bluesType(name);
   }else if(choice == 2){
      me = new rockType(name);
   }else if(choice == 3){
      me = new metalType(name);
   }

//set up guitarists and gear
   guitarist * bbKing, *ericC, * srv; 
   guitarist * slash, * jimmyP, * angusY;  
   guitarist * chuckS, * kirkH, * alexiL;
   gear * bbGuit, * ecPedal, * srvPick; 
   gear * slashAmp, * jpStrap, * ayGuit;
   gear * csPick, * khPedal, *alGuit;

   //blues guitarists and their gear
   //BB King, Eric Clapton, Stevie Ray Vaughan
   bbKing = new bluesType("BB King");
   ericC = new bluesType("Eric Clapton");
   srv = new bluesType("Stevie Ray Vaughan");
   //create their gear
   bbGuit = new gear(5,10,0,5,5,"guitar","BB King's Flying V");
   ecPedal = new gear(5,0,0,15,5,"pedal","Eric Clapton's");
   srvPick = new gear(15,5,0,5,0,"pick","Stevie Ray Vaughan's"); 
   //give them their gear
   bbKing->winGear(bbGuit,1);
   ericC->winGear(ecPedal,3);
   srv->winGear(srvPick,0);
   //set up list
   bluesList.push_back(bbKing);
   bluesList.push_back(ericC);
   bluesList.push_back(srv);

   //rock guitarists
   //Slash, Jimmy Page, Angus Young
   slash = new rockType("Slash");
   jimmyP = new rockType("Jimmy Page");
   angusY = new rockType("Angus Young");
   //create their gear
   slashAmp = new gear(0,5,5,10,5,"amp","Slash's");
   jpStrap = new gear(0,5,5,5,10,"strap","Jimmy Page's");
   ayGuit = new gear(0,20,5,0,0,"guitar","Angus Young's Gibson SG");
   //give them their gear
   slash->winGear(slashAmp,2);
   jimmyP->winGear(jpStrap,4);
   angusY->winGear(ayGuit,1);
   //set up list
   rockList.push_back(slash);
   rockList.push_back(jimmyP);
   rockList.push_back(angusY);

   //metal guitarists
   //Chuck Schuldiner, Kirk Hammett, Alexi Laiho
   chuckS = new metalType("Chuck Schuldiner");
   kirkH = new metalType("Kirk Hammett");
   alexiL = new metalType("Alexi Laiho");
   //create their gear
   csPick = new gear(15,5,5,0,0,"pick","Chuck Schuldiner's");
   khPedal = new gear(0,0,5,10,10,"pedal","Kirk Hammett's wah");
   alGuit = new gear(5,10,5,0,5,"guitar","Alexi Laiho's Greeny");
   //give them their gear
   chuckS->winGear(csPick,0);
   kirkH->winGear(khPedal,3);
   alexiL->winGear(alGuit,1);
   //set up list
   metalList.push_back(chuckS);
   metalList.push_back(kirkH);
   metalList.push_back(alexiL);  

   //legend guitarists
   //don't have specific gear because their stats are very high already.
   //Jimi Hendrix, Tony Iommi, Eddie Van Halen  
   guitarist * jimiH, * tonyI, * eddieVH;  
   jimiH = new legendType("Jimi Hendrix");
   tonyI = new legendType("Tony Iommi");
   eddieVH = new legendType("Eddie Van Halen");  
   //set up list
   legendList.push_back(jimiH);
   legendList.push_back(tonyI);
   legendList.push_back(eddieVH);

  
   //create world, which is a list.
   //space * p, * s, * a, * bBattle, * rBattle, * mBattle, *lBattle;
   p = new practiceRoom("Practice Room");  //practice is bottom 
   
   s = new studio("Studio"); //studio is on top of practice

   a = new arena("Arena"); //arena on top of studio

   bBattle = new battle("Blues Battle",bluesList);  //blues battles are on top of arena

   rBattle = new battle("Rock Battle",rockList); //rock battles are on top of 
                                                             //blues battles

   mBattle = new battle("Metal Battle",metalList); //metal battles are on top of
                                                              //rock battles

   lBattle = new battle("Legend Battle",legendList); //legend battles are at top

   //originally planned to have these set up in space constructor,
   //but kept getting seg fault whenever I tried to access them.
   //No seg fault this way though
   p->setTop(s);
   s->setBottom(p);
   s->setTop(a);
   a->setBottom(s);
   a->setTop(bBattle);
   bBattle->setBottom(a);
   bBattle->setTop(rBattle);
   rBattle->setBottom(bBattle);
   rBattle->setTop(mBattle);
   mBattle->setBottom(rBattle);
   mBattle->setTop(lBattle);
   lBattle->setBottom(mBattle);
                 
   //set starting location to practiceRoom                            
   location = p;  

}

game::~game(){
   delete me;
   me = NULL;


   for(auto i = bluesList.begin(); i != bluesList.end(); ++i){
      delete *i;
      *i = NULL;
   } 

   for(auto i = rockList.begin(); i != rockList.end(); ++i){
      delete *i;
      *i = NULL;
   } 

   for(auto i = metalList.begin(); i != metalList.end(); ++i){
      delete *i;
      *i = NULL;
   } 

   for(auto i = legendList.begin(); i != legendList.end(); ++i){
      delete *i;
      *i = NULL;
   } 

   delete p;
   delete s;
   delete a;
   delete bBattle;
   delete rBattle;
   delete mBattle; 
   delete lBattle;
}

//where the entire gameplay happens. Loop for each "day" or "move"
//is the do while loop in here.
void game::playGame(){
   int choice;
   cout << "Start of game." << endl;
   cout << endl;

   //each "day" or "move"
   do{
      //printing out generic info that could have changed
      cout << "You are at the " << location->getName() << endl;
      cout << endl;
      cout << "Your rig: " << endl;
      me->getRig();
      cout << endl;
      cout << "Your stats: " << endl;
      me->getStats();
      cout << endl;

      //menu to enter the place of which space they are on.
      //cannot enter legend battle unless all gear is non-generic
      if((me->getGear(0)->getName() == "generic" ||
         me->getGear(1)->getName() == "generic" ||
         me->getGear(2)->getName() == "generic" ||
         me->getGear(3)->getName() == "generic" ||
         me->getGear(4)->getName() == "generic") &&
         location->getName() == "Legend Battle"){
         cout << "Press 1 to go elsewhere. You cannot enter here";
         cout << " until you have all non-generic gear." << endl;
      }else{
         cout << "Press 1 to enter " << location->getName();
         cout << " or 2 to go elsewhere. " << endl;
         if(valid(1,2) == 1){
            location->play(me);
         }
      }
      cout << endl;
     
      //menu to move to a different space. If you move
      //it costs money (travel costs), whereas it is free to stay put
      cout << "Pick a direction to move or stay put." << endl;
      //can't go north if no space above you
      if(location->getTop() == NULL){
         cout << "Cannot go North." << endl;
         cout << "1. South to " << location->getBottom()->getName() << endl;
         cout << "2. Stay at " << location->getName() << endl; 
         choice = valid(1,2);
         if(choice == 1){
            location = location->getBottom();
            me->setBank(me->getBank() - 500);
         }
      }
      //can't go south if no space below you
      else if(location->getBottom() == NULL){
         cout << "Cannot go South." << endl;
         cout << "1. North to " << location->getTop()->getName() << endl;
         cout << "2. Stay at " << location->getName() << endl;
         choice = valid(1,2);
         if(choice == 1){
            location = location->getTop();
            me->setBank(me->getBank() - 500);
         }
      }
      else{
         cout << "1. North to " << location->getTop()->getName() << endl;
         cout << "2. South to " << location->getBottom()->getName() << endl;
         cout << "3. Stay at " << location->getName() << endl;
         int choice = valid(1,3);
         if(choice == 1){
            location = location->getTop();
            me->setBank(me->getBank() - 500);
         }else if(choice == 2){
            location = location->getBottom();
            me->setBank(me->getBank() - 500);
         }
      }
      cout << endl;

      //food/living costs $100 per day
      me->setBank(me->getBank() - 100);
      
      cout << endl;

   //lost or won game
   }while(me->getBank() >= 0 && lBattle->beatenBattle() != true);


}

