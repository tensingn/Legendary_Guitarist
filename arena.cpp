/**********************************************************
 * Program name: Final - arena implementation file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the implementation file for the 
 * arena class. This is a child class of the space
 * class. This is where you play live shows for your
 * fans. If you put on a killer show, you will get a
 * good amount of money from the venue, but you will
 * lose some power since putting on great live shows
 * takes lots of energy. There is a direct correlation
 * with how much you make and how much power you lose.
 * ***************************************************/

#include "arena.hpp"
#include "space.hpp"
#include "guitarist.hpp"
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//constructors
arena::arena() : space(){
   
}

arena::arena(string name) : space(name){

}

//void function that takes a guitarist pointer as a parameter. 
//The function simulates a live concert that your guitarist puts on.
//If you put on a great show, you make a lot of money but lose lots
//of power (energy) since you put your heart into it. The opposite
//is true as well.
void arena::play(guitarist * g){
   //intro
   cout << "Welcome to the arena! ";
   cout << "This is where you put on shows for your fans!" << endl;
   cout << "Kill it out there tonight, kid! " << endl;
   
   //determination of how well you performed
   int tickets = g->perform();
   cout << tickets << endl;
   
   //different scenarios depending on how well you did.
   //prints a message and gives you money and takes
   //away some power
   if(tickets > 200){
      cout << "ABSOLUTELY ELECTRIC SHOW! You earned $";
      cout << tickets*50 << " in ticket sales." << endl;
      g->setBank(g->getBank() + tickets*50);
      cout << "You now have $" << g->getBank() << endl;
      g->setPower(g->getPower() - (tickets / 25));
   }else if(tickets > 150){
      cout << "You played a great show! You earned $";
      cout << tickets*50 << " in ticket sales." << endl;
      g->setBank(g->getBank() + tickets*50);
      cout << "You now have $" << g->getBank() << endl;
      g->setPower(g->getPower() - (tickets / 25));
   }else if(tickets > 100){
      cout << "Solid performance tonight. You earned $";
      cout << tickets*50 << " in ticket sales." << endl;
      g->setBank(g->getBank() + tickets*50);
      cout << "You now have $" << g->getBank() << endl;
      g->setPower(g->getPower() - (tickets / 25));
   }else if (tickets > 50){
      cout << "OK show tonight. You earned $";
      cout << tickets*50 << " in ticket sales." << endl;
      g->setBank(g->getBank() + tickets*50);
      cout << "You now have $" << g->getBank() << endl;
      g->setPower(g->getPower() - (tickets / 25));
   }else{
      cout << "Where was the energy tonight? ";
      cout << "You looked dead. You earned $";
      cout << tickets*50 << " in tickets sales." << endl;
      g->setBank(g->getBank() + tickets*50);
      cout << "You now have $" << g->getBank() << endl;
      g->setPower(g->getPower() - (tickets / 25));
   }
}


