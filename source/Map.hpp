#ifndef MAP
#define MAP
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../rsdllib/rsdl.hpp"
#include "Mario.hpp"
#include "Block.hpp"
#include "Pipe.hpp"
#include "QuestionBrick.hpp"
#include "Coin.hpp"
#include "Flag.hpp"
#include "Goomba.hpp"
#include "Koopa.hpp"
#include "RedMushroom.hpp"
#include "HealthMushroom.hpp"

#define USED 1
#define UNUSED -1
#define QUESTION_1 "question-1.png"
#define QUESTION_2 "question-2.png"
#define QUESTION_3 "question-3.png"
#define QUESTION_4 "question-empty.png"
#define FULL 1
#define EMPTY -1
#define COIN_SOUND "sounds/coin.wav"
#define POWERUP_APEARS_SOUND "sounds/powerup-appears.wav"
#define DEFUALT_WIDTH 32
#define HEAD_LEFT_PIPE "head-left.png"
#define HEAD_RIGHT_PIPE "head-right.png"
#define LEFT_PIPE "left.png"
#define RIGHT_PIPE "right.png"
#define PIPE '|'
#define MARIO 'M'
#define BLOCK_TYPE1 'b'
#define BLOCK_TYPE2 '@'
#define BLOCK_TYPE3 '#'
#define BRICK "brick.png"
#define BLOCK "block.png"
#define CLAY "clay.png"
#define QUESTION_BRICK_TYPE1 '?'
#define QUESTION_BRICK_TYPE2 'm'
#define QUESTION_BRICK_TYPE3 'h'
#define FLAG 'f'
#define FLAG_BODY "body"
#define FLAG_HEAD "head"
#define GOOMBA 'l'
#define KOOPA 'k'
#define FRONT 1
#define BACK -1
#define UP 2
#define DOWN -2
#define _GOOMBA 1
#define _KOOPA 2
#define RIGHT "right"
#define LEFT "left"
#define DYING "dead"
#define UNKICKED 1
#define KICKED -1
#define SMASHED "brick-debris.png"
#define DEFUALT_GOOMBA_LIFE 800

using namespace std;


class Map{
public:
  void readMapData(string fileName);
  vector<string> getPlot();
  void fillMap();
  void freeMap();
  void resetMap();
  void makeMapReady(string fileName);
  void addBlocks(char object, Point _position);
  void addQuestionBricks(char object ,Point _position);
  void addPipe(char object ,Point _position);
  void addFlag(char object ,Point _position ,char previous);
  void addGoomba(char object ,Point _position);
  void addKoopa(char object ,Point _position);
  void changQuestionBricksStyle();
  vector<Block> getBlocks();
  vector<QuestionBrick> getQuestionBricks();
  vector<Pipe> getPipes();
  vector<Flag> getFlag();
  vector<Coin> getCoin();
  vector<Goomba> getGoombas();
  vector<Koopa> getKoopas();
  vector<RedMushroom> getRedMushrooms();
  vector<HealthMushroom> getHealthMushrooms();
  string findPipeType(Point position);
  Point findMarioPosition();
  bool existAnObject(int direction ,Point position ,int width ,int height);
  bool hitAnEnemy(int direction ,int enemyType ,Point position ,int width ,int height);
  bool existBlocks(Point cranny ,int length ,int direction ,int& objectCounter);
  bool existQuestionBricks(Point cranny ,int length ,int direction ,int& objectCounter);
  bool existPipes(Point cranny ,int length ,int direction ,int& objectCounter);
  bool hitGoomba(Point cranny ,int length ,int direction ,int& objectCounter);
  bool hitKoopa(Point cranny ,int length ,int direction ,int& objectCounter);
  bool eatRedMushroom(Point cranny ,int length ,int direction ,int& objectCounter);
  bool eatHealthMushroom(Point cranny ,int length ,int direction ,int& objectCounter);
  Point findCranny(int direction ,Point position ,int width);
  bool checkLength(int x1 ,int y1 ,int x2 ,int y2);
  void handleGoombasDirections();
  void handleKoopasDirections();
  void handleRedMushroomsDirections();
  void handleHealthMushroomsDirections();
  void handleGoombasMovings(int start ,int end);
  void handleKoopasMovings(int start ,int end);
  void handleMushroomsMovings();
  void goombasFalling(int start ,int end);
  void koopasFalling(int start ,int end);
  void redMushroomsFalling();
  void healthMushroomsFalling();
  bool marioReachFlag(int x);
  void givePowerUp(int objectCounter ,Mario& mario ,Window& window);
  void risingOfCoins(int& coinCounter);
  void tremblingQuestion(int objectCounter ,int direction);
  void tremblingBrick(int objectCounter ,int direction);
  void smashingBrick(int objectCounter);
  void setRedMushroomUnused(int objectCounter);
  void setHealthMushroomUnused(int objectCounter);
  void removeBrick(int objectCounter);
  void setGoombaDead(int objectCounter);
  void setKoopaDead(int objectCounter);
  void removeGoomba(int objectCounter);
  void removeKoopa(int objectCounter);
  void goombasLastStand();
  void kickingKoopas(int objectCounter ,int direction);
private:
  vector<string> plot;
  vector<Block> blocks;
  vector<QuestionBrick> questionBricks;
  vector<Pipe> pipes;
  vector<Goomba> goombas;
  vector<Koopa> koopas;
  vector<Flag> flag;
  vector<Coin> coins;
  vector<RedMushroom> redMushrooms;
  vector<HealthMushroom> healthMushrooms;
};

#endif
