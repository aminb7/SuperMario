#include "QuestionBrick.hpp"


QuestionBrick::QuestionBrick(Point _position, int _type):position(_position) {
  type = _type;
}

Point QuestionBrick::getPosition() {
  return position;
}

string QuestionBrick::getSituation(){
  return situation;
}

int QuestionBrick::getInside(){
  return inside;
}

void QuestionBrick::setInside(int _inside){
  inside = _inside;
}

void QuestionBrick::setSituation(string _situation){
  situation = _situation;
}

void QuestionBrick::setPosition(Point _position){
  position = _position;
}

int QuestionBrick::getType(){
  return type;
}

void QuestionBrick::changStyle(){
  if(situation == QUESTION_1){
    situation = QUESTION_2;
    return;
  }
  if(situation == QUESTION_2){
    situation = QUESTION_3;
    return;
  }
  if(situation == QUESTION_3){
    situation = QUESTION_1;
    return;
  }
}
