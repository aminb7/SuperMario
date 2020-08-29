#ifndef KOOPA
#define KOOPA
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "../rsdllib/rsdl.hpp"

#define FIRST_FALLING_VELOCITY 2
#define DEFUALT_WIDTH 32
#define UNKICKED 1
#define KICKED -1
#define RIGHT "right"
#define LEFT "left"
#define WALKING_TYPE1 "walking-1"
#define WALKING_TYPE2 "walking-2"
#define KOOPA_ADDRESS "enemies/koopa_troopa"
#define SLASH "/"
#define DYING "dead"
#define MINUS "-"

using namespace std;

class Koopa{
public:
  Koopa(Point _position );
  Point getPosition();
  string imageAddress();
  void move();
  void fall();
  void kick();
  void setDirection(string _direction);
  void setSituation(string _situation);
  void setFallingVelocity(int velocity);
  void setKickingSituation(int _kickingSituation);
  string getSituation();
  int getWidth();
  int getHeight();
  string getDirection();
  int getKickingSituation();
  void changWalkingStyle();
private:
  Point position;
  int fallingVelocity = FIRST_FALLING_VELOCITY;
  int width = DEFUALT_WIDTH;
  int height = DEFUALT_WIDTH;
  int kickingSituation = UNKICKED;
  string direction = LEFT;
  string situation = WALKING_TYPE1;
};

#endif
