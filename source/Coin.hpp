#ifndef COIN
#define COIN
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "../rsdllib/rsdl.hpp"

#define COIN_PEAK 4
#define DEFUALT_WIDTH 32
#define USED 1
#define UNUSED -1

using namespace std;

class Coin{
public:
  Coin(Point _position);
  void rise();
  int getSituation();
  Point getPosition();
private:
  Point position;
  int peak = COIN_PEAK;
  int distanceCovered = 0;
  int width = DEFUALT_WIDTH;
  int height = DEFUALT_WIDTH;
  int situation = USED;
};

#endif
