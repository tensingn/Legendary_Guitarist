/**********************************************************
 * Program name: Final - studio implementation file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the implementation file for the 
 * studio class. This is a child class of the space
 * class. In the studio, you pay money to record your
 * music. Then you have the opportunity to win lots
 * of money if your record hits it big. But you could
 * also just lose the money you paid to record if no
 * one likes your stuff. You are more likely to put
 * out a successful record if your skills are high.
 * ***************************************************/

#include "space.hpp"
#include "studio.hpp"
#include "guitarist.hpp"
#include <cstdlib>
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

studio::studio() : space(){

}

studio::studio(string name) : space(name){
   
}

//void function that takes guitarist pointer as parameter.
//Simulates guitarist creating a record in the studio
void studio::play(guitarist * g){
   //intro
   cout << "Welcome to the studio! ";
   cout << "You have the chance to record a hit album!" << endl;
   cout << "It costs $7500 to record your album. " << endl;
   
   //pay for recording, randomly get sales
   g->setBank(g->getBank() - 7500);
   int sales = g->perform();
   cout << sales << endl;
   
   //scenerios based on how well you did
   if(sales > 200){
      cout << "Your record was a huge hit! You earned $";
      cout << sales*100 << " in sales." << endl;
      g->setBank(g->getBank() + sales*100);
      cout << "You now have $" << g->getBank() << endl;
   }else if(sales > 150){
      cout << "Your released a great record! You earned $";
      cout << sales*100 << " in sales." << endl;
      g->setBank(g->getBank() + sales*100);
      cout << "You now have $" << g->getBank() << endl;
   }else if(sales > 100){
      cout << "You put out a solid record. You earned $";
      cout << sales*100 << " in sales." << endl;
      g->setBank(g->getBank() + sales*100);
      cout << "You now have $" << g->getBank() << endl;
   }else if (sales > 50){
      cout << "Your record OK. You earned $";
      cout << sales*100 << " in sales." << endl;
      g->setBank(g->getBank() + sales*100);
      cout << "You now have $" << g->getBank() << endl;
   }else{
      cout << "Your record flopped. You earned $";
      cout << sales*100 << " in sales." << endl;
      g->setBank(g->getBank() + sales*100);
      cout << "You now have $" << g->getBank() << endl;
   }
}


