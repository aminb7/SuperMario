#include "Pipe.hpp"


Pipe::Pipe(Point _position , string _type) :position(_position) {
type = _type;
}

Point Pipe::getPosition(){
  return position;
}

string Pipe::getType(){
  return type;
}
