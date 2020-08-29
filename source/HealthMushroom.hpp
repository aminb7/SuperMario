#ifndef HEALTH_MUSHROOM
#define HEALTH_MUSHROOM
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "../rsdllib/rsdl.hpp"

#define RIGHT "right"
#define LEFT "left"
#define USED 1
#define UNUSED -1
#define FIRST_FALLING_VELOCITY 2
#define DEFUALT_WIDTH 32

using namespace std;

class HealthMushroom{
public:
  HealthMushroom(Point _position);
  void setDirection(string _direction);
  string getDirection();
  Point getPosition();
  int getWidth();
  int getHeight();
  void move();
  void fall();
private:
  Point position;
  string direction = RIGHT;
  int situation = USED;
  int fallingVelocity = FIRST_FALLING_VELOCITY;
  int width = DEFUALT_WIDTH;
  int height = DEFUALT_WIDTH;
};

#endif
