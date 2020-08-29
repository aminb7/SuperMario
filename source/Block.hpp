#ifndef BLOCK
#define BLOCK
#include <cstdlib>
#include <string>
#include "../rsdllib/rsdl.hpp"

#define DEFUALT_WIDTH 32

using namespace std;

class Block{
public:
  Block(Point _position, string _type);
  Point getPosition();
  string getType();
  void setPosition(Point _position);
  void setSituation(string _type);
public:
  Point position;
  int width = DEFUALT_WIDTH;
  int height = DEFUALT_WIDTH;
  string type;
};

#endif
