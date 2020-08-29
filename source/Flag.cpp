#include "Flag.hpp"



Flag::Flag(Point _position , string _type):position(_position) {
type = _type;
}

Point Flag::getPosition(){
   return position;
}

string Flag::getType(){
  return type;
}
