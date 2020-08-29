#include "Coin.hpp"



Coin::Coin(Point _position) :position(_position) {}

int Coin::getSituation(){
  return situation;
}

Point Coin::getPosition(){
   return position;
}

void Coin::rise(){
  position = Point(position.x , position.y - 1);
  distanceCovered += 2;
  if(distanceCovered == peak)
    situation = UNUSED;
}
