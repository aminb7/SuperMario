#ifndef FLAG
#define FLAG
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "../rsdllib/rsdl.hpp"

#define DEFUALT_WIDTH 32

using namespace std;

class Flag{
public:
  Flag(Point _position , string _type);
  Point getPosition();
  string getType();
private:
  Point position;
  int width = DEFUALT_WIDTH;
  int height = DEFUALT_WIDTH;
  string type;
};

#endif
