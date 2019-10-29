/**********************************************************
 * Program name: Final - bluesType header file
 * Author: Nicholas Tensing
 * Date: 6/11/19
 * Description: header file for the bluesType class. This
 * is a child of the guitarist class.
 * *******************************************************/

#include "guitarist.hpp"
#include <string>
using std::string;

#ifndef BLUESTYPE_HPP
#define BLUESTYPE_HPP

class bluesType : public guitarist{
public:
   bluesType();
   bluesType(string);
};

#endif

