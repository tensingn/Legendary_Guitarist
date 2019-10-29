/**********************************************************
 * Program name: Final - arena header file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the header file for the 
 * arena class. This is a child class of the space
 * class. This is where you play live shows for your
 * fans. If you put on a killer show, you will get a
 * good amount of money from the venue, but you will
 * lose some power since putting on great live shows
 * takes lots of energy.
 * ***************************************************/

#include "space.hpp"
#include "guitarist.hpp"
#include <string>
using std::string;

#ifndef ARENA_HPP
#define ARENA_HPP

class arena : public space{
public:
   arena();
   arena(string);
   void play(guitarist *);
};


#endif


