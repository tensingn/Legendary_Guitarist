/**********************************************************
 * Program name: Final - practiceRoom implementation file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the implementation file for the 
 * practiceRoom class. This is a child of the space 
 * class. In the practice room, you spend money and
 * improve your skills. You don't really get better,
 * you just get more consistent. So, when you battle, 
 * the max score you can get for a certain stat will
 * be unaffected by practice, but the min score you
 * can get will be increased by practice. The reason
 * for this is so the user can't just practice a 
 * bunch in a row to get all stats as high as possible,
 * since practice is pretty cheap.  
 * ***************************************************/

#include "space.hpp"
#include "practiceRoom.hpp"
#include "guitarist.hpp"
#include <cstdlib>
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

practiceRoom::practiceRoom() : space(){
   
}

practiceRoom::practiceRoom(string name) : space(name){

}

//pay $250 per practice session. Improve minskill randomly
void practiceRoom::play(guitarist * player){
   cout << endl;
   cout << "Welcome to the practice room! " << endl;

   //price to practice
   cout << "$250 per session." << endl;
   player->setBank(player->getBank() - 250);
   
   //randomly improving players minSkill
   int improve = rand() % 10;
   player->setMinSkill(player->getMinSkill() + improve);
   cout << "You improved your minSkill by " << improve << endl;
   


}






