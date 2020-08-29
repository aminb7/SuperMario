#ifndef MARIO
#define MARIO
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "../rsdllib/rsdl.hpp"

#define FIRST_FALLING_VELOCITY 2
#define FIRST_JUMPING_VELOCITY 1
#define SMALL_MARIO_WIDTH 32
#define SMALL_MARIO_HEIGHT 32
#define BIG_MARIO_HEIGHT 50
#define RIGHT "right"
#define LEFT "left"
#define STANDING "standing"
#define JUMPING "jumping"
#define SLIDING "sliding"
#define DEAD "dead"
#define NORMAL "normal"
#define BIG "big"
#define WALKING "walking"
#define DEFUALT_LIVES 3
#define DEFUALT_PEAK 160
#define MINUS "-"
#define SLASH "/"
#define MARIO_ADDRESS "mario/"
#define FRONT 1
#define BACK -1
#define WALKING_TYPE1 "walking-1"
#define WALKING_TYPE2 "walking-2"
#define WALKING_TYPE3 "walking-3"

using namespace std;

class Mario{
public:
  Mario(Point _position);
  void move(int direction);
  void slide();
  void fall();
  void jump();
  void die();
  void becomeBig();
  void becomeNormal();
  string imageAddress();
  Point getPosition();
  string getSituation();
  void setDirection(string _direction);
  void changWalkingStyle();
  void nextWalkingStyle();
  int getDirection();
  int getCoins();
  void setPosition(Point _position);
  void setSituation(string _situation);
  void setFallingVelocity(int velocity);
  int getWidth();
  int setDistanceCovered(int _distanceCovered);
  int getHeight();
  int getLives();
  string getsize();
  bool reachPeak();
  void addCoin();
  void addLive();
private:
  int lives = DEFUALT_LIVES;
  int coins = 0;
  Point position;
  Point startingPosition;
  int fallingVelocity = FIRST_FALLING_VELOCITY;
  int jumpingVelocity = FIRST_JUMPING_VELOCITY;
  int distanceCovered = 0;
  int peak = DEFUALT_PEAK;
  int width = SMALL_MARIO_WIDTH;
  int height = SMALL_MARIO_HEIGHT;
  string direction = RIGHT;
  string situation = STANDING;
  string size = NORMAL;
};

#endif
