#include "Block.hpp"


Block::Block(Point _position, string _type):position(_position) {
  type = _type;
}

Point Block::getPosition(){
 return position;
}

string Block::getType(){
  return type;
}

void Block::setPosition(Point _position){
  position = _position;
}

void Block::setSituation(string _type){
  type = _type;
}
