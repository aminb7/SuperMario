#include "Koopa.hpp"


Koopa::Koopa(Point _position ) :position(_position){}

Point Koopa::getPosition(){
  return position;
}

void Koopa::setDirection(string _direction){
  direction = _direction;
}

void Koopa::setSituation(string _situation){
  situation = _situation;
}

void Koopa::setFallingVelocity(int velocity){
  fallingVelocity = velocity;
}

void Koopa::setKickingSituation(int _kickingSituation){
  kickingSituation = _kickingSituation;
}

string Koopa::getSituation(){
  return situation;
}

int Koopa::getWidth(){
  return width;
}

int Koopa::getHeight(){
  return height;
}

string Koopa::getDirection(){
  return direction;
}

int Koopa::getKickingSituation(){
  return kickingSituation;
}

string Koopa::imageAddress(){
  string imageAddress = KOOPA_ADDRESS;
  imageAddress.append(SLASH);
  imageAddress.append(situation);
  if(situation != DYING){
    imageAddress.append(MINUS);
    imageAddress.append(direction);
  }
  imageAddress.append(".png");
  return imageAddress;
}

void Koopa::move(){
  if(direction == RIGHT)
    position = Point(position.x + 2, position.y);
  if(direction == LEFT)
    position = Point(position.x - 2, position.y);
}

void Koopa::kick(){
  if(direction == RIGHT)
    position = Point(position.x + 10, position.y);
  if(direction == LEFT)
    position = Point(position.x - 10, position.y);
}

void Koopa::fall(){
  position = Point(position.x , position.y + fallingVelocity);
}

void Koopa::changWalkingStyle(){
  if(situation == WALKING_TYPE1){
    situation = WALKING_TYPE2;
    return;
  }
  if(situation == WALKING_TYPE2){
    situation = WALKING_TYPE1;
    return;
  }
}
