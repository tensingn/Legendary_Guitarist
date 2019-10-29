/**********************************************************
 * Program name: Final - rockType header file
 * Author: Nicholas Tensing
 * Date: 6/3/19
 * Description: This is the header file for the 
 * rockType class.
 * *******************************************************/

#include "guitarist.hpp"
#include <string>
using std::string;

#ifndef ROCKTYPE_HPP
#define ROCKTYPE_HPP

class rockType : public guitarist{
public:
   rockType();
   rockType(string);
};

#endif

