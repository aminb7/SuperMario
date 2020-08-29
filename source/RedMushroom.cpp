#include "RedMushroom.hpp"


RedMushroom::RedMushroom(Point _position) :position(_position) {}

void RedMushroom::setDirection(string _direction){
  direction = _direction;
}

string RedMushroom::getDirection(){
  return direction;
}

Point RedMushroom::getPosition(){
  return position;
}

int RedMushroom::getWidth(){
  return width;
}

int RedMushroom::getHeight(){
  return height;
}

void RedMushroom::move(){
  if(direction == RIGHT)
    position = Point(position.x + 2, position.y);
  if(direction == LEFT)
    position = Point(position.x - 2, position.y);
}

void RedMushroom::fall(){
  position = Point(position.x , position.y + fallingVelocity);
}
