/**********************************************************
 * Program name: Final - legendType header file
 * Author: Nicholas Tensing
 * Date: 6/3/19
 * Description: This is the header file for the 
 * legendType class. Their stats overall are much better
 * than everyone else.
 * *******************************************************/

#include "guitarist.hpp"
#include <string>
using std::string;

#ifndef LEGENDTYPE_HPP
#define LEGENDTYPE_HPP

class legendType : public guitarist{
public:
   legendType();
   legendType(string);
};

#endif

