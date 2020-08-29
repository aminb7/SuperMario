#ifndef QUESTION_BRICK
#define QUESTION_BRICK
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../rsdllib/rsdl.hpp"

#define DEFUALT_WIDTH 32
#define FULL 1
#define EMPTY -1
#define QUESTION_1 "question-1.png"
#define QUESTION_2 "question-2.png"
#define QUESTION_3 "question-3.png"
#define QUESTION_4 "question-empty.png"

using namespace std;

class QuestionBrick{
public:
  QuestionBrick(Point _position, int _type);
  Point getPosition();
  void changStyle();
  string getSituation();
  int getInside();
  void setInside(int _inside);
  void setSituation(string _situation);
  void setPosition(Point _position);
  int getType();
private:
  Point position;
  int width = DEFUALT_WIDTH;
  int height = DEFUALT_WIDTH;
  int type;
  int inside = FULL;
  string situation = QUESTION_1;
};

#endif
