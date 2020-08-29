#include "Mario.hpp"



Mario::Mario(Point _position) :position(_position) ,startingPosition(_position){}

Point Mario::getPosition(){
  return position;
}

string Mario::getSituation(){
  return situation;
}

void Mario::setDirection(string _direction){
  direction = _direction;
}

int Mario::getCoins(){
  return coins;
}

void Mario::setPosition(Point _position){
  position = _position;
}

void Mario::setSituation(string _situation){
  situation = _situation;
}

void Mario::setFallingVelocity(int velocity){
  fallingVelocity = velocity;
}

int Mario::getWidth(){
  return width;
}

int Mario::setDistanceCovered(int _distanceCovered){
  distanceCovered = _distanceCovered;
}

int Mario::getHeight(){
  return height;
}

int Mario::getLives(){
  return lives;
}

string Mario::getsize(){
  return size;
}

void Mario::addCoin(){
  coins++;
}

void Mario::addLive(){
  lives++;
}

bool Mario::reachPeak(){
  if(distanceCovered == peak)
    return true;
  return false;
}

void Mario::move(int direction){
  position = Point(position.x + (direction * 5), position.y);
}

void Mario::slide(){
  setSituation(SLIDING);
  position = Point(position.x + (getDirection() * 3), position.y);
}

void Mario::fall(){
  position = Point(position.x , position.y + fallingVelocity);
}

void Mario::jump(){
  position = Point(position.x , position.y - jumpingVelocity);
  distanceCovered += jumpingVelocity;
  if(distanceCovered == peak){
    setSituation(STANDING);
    distanceCovered = 0;
  }
}

void Mario::die(){
  setSituation(STANDING);
  position = startingPosition;
  lives--;
}

void Mario::becomeBig(){
  if(size != BIG){
    size = BIG;
    width = BIG_MARIO_HEIGHT;
    height = BIG_MARIO_HEIGHT;
    position = Point(position.x , position.y - 18);
  }
}

void Mario::becomeNormal(){
  if(size == BIG){
    size = NORMAL;
    width = SMALL_MARIO_WIDTH;
    height = SMALL_MARIO_WIDTH;
    position = Point(position.x , position.y + 18);
  }
}

string Mario::imageAddress(){
  string imageAddress = MARIO_ADDRESS;
  imageAddress.append(size);
  imageAddress.append(SLASH);
  imageAddress.append(situation);
  if(situation != DEAD){
    imageAddress.append(MINUS);
    imageAddress.append(direction);
  }
  imageAddress.append(".png");
  return imageAddress;
}

int Mario::getDirection(){
  if(direction == RIGHT)
    return FRONT;
  if(direction == LEFT)
    return BACK;
}

void Mario::nextWalkingStyle(){
  if(situation == WALKING_TYPE1){
    situation = WALKING_TYPE2;
    return;
  }
  if(situation == WALKING_TYPE2){
    situation = WALKING_TYPE3;
    return;
  }
  if(situation == WALKING_TYPE3){
    situation = WALKING_TYPE1;
    return;
  }
}

void Mario::changWalkingStyle(){
  if(situation.substr(0 ,7) != WALKING)
    situation = WALKING_TYPE1;
  else{
    nextWalkingStyle();
  }
}
