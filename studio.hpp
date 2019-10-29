/**********************************************************
 * Program name: Final - studio header file
 * Author: Nicholas Tensing
 * Date: 6/3/19
 * Description: This is the header file for the 
 * studio class. This is a child class of the space
 * class. In the studio, you pay money to record your
 * music. Then you have the opportunity to win lots
 * of money if your record hits it big. But you could
 * also just lose the money you paid to record if no
 * one likes your stuff. You are more likely to put
 * out a successful record if your skills are high.
 * ***************************************************/

#include "space.hpp"
#include "guitarist.hpp"
#include <string>
using std::string;

#ifndef STUDIO_HPP
#define STUDIO_HPP

class studio : public space{
public:
   studio();
   studio(string);
   void play(guitarist *);
};



#endif
