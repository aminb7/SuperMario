#ifndef GOOMBA
#define GOOMBA
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "../rsdllib/rsdl.hpp"

#define FIRST_FALLING_VELOCITY 2
#define DEFUALT_WIDTH 32
#define RIGHT "right"
#define LEFT "left"
#define WALKING_TYPE1 "walking-1"
#define WALKING_TYPE2 "walking-2"
#define GOOMBA_ADDRESS "enemies/little_goomba"
#define SLASH "/"

using namespace std;

class Goomba{
public:
  Goomba(Point _position );
  Point getPosition();
  string imageAddress();
  void move();
  void fall();
  void setDirection(string _direction);
  void setSituation(string _situation);
  void setFallingVelocity(int velocity);
  string getSituation();
  int getLastStand();
  int getWidth();
  int getHeight();
  string getDirection();
  void changWalkingStyle();
  void addLastStand();
private:
  Point position;
  int fallingVelocity = FIRST_FALLING_VELOCITY;
  int width = DEFUALT_WIDTH;
  int height = DEFUALT_WIDTH;
  int lastStand = 0;
  string direction = LEFT;
  string situation = WALKING_TYPE1;
};

#endif
