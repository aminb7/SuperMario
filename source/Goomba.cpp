#include "Goomba.hpp"



Goomba::Goomba(Point _position ) :position(_position){}

Point Goomba::getPosition(){
  return position;
}

void Goomba::setDirection(string _direction){
  direction = _direction;
}

void Goomba::setSituation(string _situation){
  situation = _situation;
}

void Goomba::setFallingVelocity(int velocity){
  fallingVelocity = velocity;
}

string Goomba::getSituation(){
  return situation;
}

int Goomba::getLastStand(){
  return lastStand;
}

int Goomba::getWidth(){
  return width;
}

int Goomba::getHeight(){
  return height;
}

string Goomba::getDirection(){
  return direction;
}

void Goomba::addLastStand(){
  lastStand++;
}

string Goomba::imageAddress(){
  string imageAddress = GOOMBA_ADDRESS;
  imageAddress.append(SLASH);
  imageAddress.append(situation);
  imageAddress.append(".png");
  return imageAddress;
}

void Goomba::move(){
  if(direction == RIGHT)
    position = Point(position.x + 2, position.y);
  if(direction == LEFT)
    position = Point(position.x - 2, position.y);
}

void Goomba::fall(){
  position = Point(position.x , position.y + fallingVelocity);
}

void Goomba::changWalkingStyle(){
  if(situation == WALKING_TYPE1){
    situation = WALKING_TYPE2;
    return;
  }
  if(situation == WALKING_TYPE2){
    situation = WALKING_TYPE1;
    return;
  }
}
