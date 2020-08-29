#include "HealthMushroom.hpp"


HealthMushroom::HealthMushroom(Point _position) :position(_position) {}

void HealthMushroom::setDirection(string _direction){
  direction = _direction;
}

string HealthMushroom::getDirection(){
  return direction;
}

Point HealthMushroom::getPosition(){
  return position;
}

int HealthMushroom::getWidth(){
  return width;
}

int HealthMushroom::getHeight(){
  return height;
}

void HealthMushroom::move(){
  if(direction == RIGHT)
    position = Point(position.x + 2, position.y);
  if(direction == LEFT)
    position = Point(position.x - 2, position.y);
}

void HealthMushroom::fall(){
  position = Point(position.x , position.y + fallingVelocity);
}
