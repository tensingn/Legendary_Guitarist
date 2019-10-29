/**********************************************************
 * Program name: Final - guitarist implementation file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the implementation file for the abstract 
 * guitarist class. There are a few different types of 
 * guitarist, which are based on genres of music. The 
 * types are children classes of the guitarist class.
 * *******************************************************/

//#include "space.hpp"
#include "guitarist.hpp"
#include "gear.hpp"

#include <cstdlib>
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

guitarist::guitarist(){
   speed = 0;
   riffing = 0;
   power = 0;
   emotion = 0;
   style = 0;
   bank = 0;
   minSkill = 1; //lower limit for random function in perform function
   name = "";
}

//can only have 1 of each rig item, so 5 items total
guitarist::guitarist(string name){
   this->name = name;
   bank = 5000; //always start player with 5000
   rig[0] = new gear("pick");
   rig[1] = new gear("guitar");
   rig[2] = new gear("amp");
   rig[3] = new gear("pedal");
   rig[4] = new gear("strap");   
   minSkill = 1;
}

guitarist::~guitarist(){
   for(int i = 0; i < 5; i++){
      delete rig[i];
   }
}

int guitarist::getSpeed(){
   return speed;
}   

void guitarist::setSpeed(int speed){
   this->speed = speed;
}

int guitarist::getRiffing(){
   return riffing;
}

void guitarist::setRiffing(int riffing){
   this->riffing = riffing;
}

int guitarist::getPower(){
   return power;
}

void guitarist::setPower(int power){
   this->power = power;
}

int guitarist::getEmotion(){
   return emotion;
}

void guitarist::setEmotion(int emotion){
   this->emotion = emotion;
}
  
int guitarist::getStyle(){
   return style;
}

void guitarist::setStyle(int style){
   this->style = style;
}

int guitarist::getBank(){
   return bank;
}

void guitarist::setBank(int bank){
   this->bank = bank;
}

int guitarist::getMinSkill(){
   return minSkill;
}

void guitarist::setMinSkill(int minSkill){
   this->minSkill = minSkill;
}

void guitarist::getStats(){
   cout << "Speed: " << speed << endl;
   cout << "Riffing: " << riffing << endl;
   cout << "Power: " << power << endl;
   cout << "Emotion: " << emotion << endl;
   cout << "Style: " << style << endl;
   cout << "MinSkily: " << minSkill << endl;
   cout << "Money: " << bank << endl;
}

string guitarist::getName(){
   return name;
}

void guitarist::setName(string name){
   this->name = name;
}

string guitarist::getType(){
   return type;
}

//simulates the guitarist's performance. For each stat, there
//will be a random value generated between minSkill and the level
//for that stat. The function returns the sum of the random value
//generated for each stat
int guitarist::perform(){
   //rand values for each 
   int randSpeed = rand() % (speed - minSkill) + minSkill;
   int randRiffing = rand() % (riffing - minSkill) + minSkill;
   int randPower = rand() % (power - minSkill) + minSkill;
   int randEmotion = rand() % (emotion - minSkill) + minSkill;
   int randStyle = rand() % (style - minSkill) + minSkill;
   
   //print what their score was
   cout << name << ": " << randSpeed + randRiffing + randPower + randEmotion + randStyle << endl;
   return randSpeed + randRiffing + randPower + randEmotion + randStyle;

}

gear * guitarist::getGear(int g){
   return rig[g];
}

//when guitarist wins a battle, they win a piece of gear from 
//their opponent. also used to set gear at creation of guitarist
void guitarist::winGear(gear * item, int g){
   //remove boosts from old gear
   speed = speed - rig[g]->getSpeed(); 
   riffing = riffing - rig[g]->getRiffing();
   power = power - rig[g]->getPower();
   emotion = emotion - rig[g]->getEmotion();
   style = style - rig[g]->getStyle();

   //delete old gear and add new gear
   delete rig[g];   
   rig[g] = item;   

   //add boosts for new gear
   speed = speed + rig[g]->getSpeed(); 
   riffing = riffing + rig[g]->getRiffing();
   power = power + rig[g]->getPower();
   emotion = emotion + rig[g]->getEmotion();
   style = style + rig[g]->getStyle();
   
}

//if guitarist loses a battle, they must give up one of their 
//non-generic pieces of gear.
void guitarist::loseGear(int g){
   string gtype = rig[g]->getType(); //so we know which type of generic
                                    //gear to create

   //remove boosts from old gear
   speed = speed - rig[g]->getSpeed(); 
   riffing = riffing - rig[g]->getRiffing();
   power = power - rig[g]->getPower();
   emotion = emotion - rig[g]->getEmotion();
   style = style - rig[g]->getStyle();

   //delete current gear and add downgrade to generic gear
   delete rig[g];   
   rig[g] = new gear(gtype);   

   //don't need to add boosts for new gear since new gear 
   //is generic gear and has no boosts
}

//prints out guitarists current rig
void guitarist::getRig(){
   for(int i = 0; i < 5; i++){
      cout << rig[i]->getName() << " ";
      cout << rig[i]->getType() << endl;
   }
}
