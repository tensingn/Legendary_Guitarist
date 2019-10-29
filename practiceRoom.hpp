/**********************************************************
 * Program name: Final - practiceRoom header file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: This is the header file for the 
 * practiceRoom class. This is a child of the space 
 * class. In the practice room, you spend money and
 * improve your skills. You don't really get better,
 * you just get more consistent. So, when you battle, 
 * the max score you can get for a certain stat will
 * be unaffected by practice, but the min score you
 * can get will be increased by practice.   
 * ***************************************************/

#include "space.hpp"
#include "guitarist.hpp"
#include <string>
using std::string;

#ifndef PRACTICEROOM_HPP
#define PRACTICEROOM_HPP

class practiceRoom : public space{
public:
   practiceRoom();
   practiceRoom(string);
   void play(guitarist *);
};



#endif
