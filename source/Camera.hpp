#ifndef CAMERA
#define CAMERA
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "../rsdllib/rsdl.hpp"
#include "Map.hpp"
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

#define START_SHOT_POINT 0
#define DEFUALT_SHOT_WIDTH 960
#define DEAD "dead"
#define UP 2
#define DOWN -2
#define BUMP_SOUND "sounds/bump.wav"
#define BRICK_SMASH_SOUND "sounds/brick-smash.wav"
#define DEFUALT_WIDTH 32
#define OBJECTS_ADDRESS "objects/"
#define FLAG_ADDRESS "flag/"
#define COIN_ADDRESS "coin.png"
#define USED 1
#define UNUSED -1
#define RED_MUSHROOM_ADDRESS "mushroom/red.png"
#define HEALTH_MUSHROOM_ADDRESS "mushroom/health.png"
#define BACKGROUND_ADDRESS "background/background_image.png"
#define MARIO_FONT "mario_font.ttf"

using namespace std;

class Camera{
public:
  Camera(int _screenWidth, int _screenHeight);
  void showScreen(Map map ,Window& window ,Mario mario);
  void showBlocks(vector<Block> blocks ,Window& win);
  void showQuestionBricks(vector<QuestionBrick> questionBricks ,Window& win);
  void showPipes(vector<Pipe> pipes ,Window& win);
  void showFlag(vector<Flag> flag ,Window& win);
  void showCoins(vector<Coin> coins ,Window& win);
  void showRedMushrooms(vector<RedMushroom> redMushrooms ,Window& win);
  void showHealthMushrooms(vector<HealthMushroom> healthMushrooms ,Window& win);
  void showGoombas(vector<Goomba> goombas ,Window& win);
  void showKoopas(vector<Koopa> koopas ,Window& win);
  void showObjects(Map map, Window& window);
  void showMario(Mario mario ,Window& window);
  void showBackground(Window& window);
  void showCoinsAndLives(Mario mario ,Window& window);
  void move();
  void marioActDying(Mario& mario ,Map map ,Window& window);
  void actQuestionTrembling(Mario mario ,Map& map ,Window& window ,int objectCounter);
  void actBrickTrembling(Mario mario ,Map& map ,Window& window ,int objectCounter);
  void actBrickSmashing(Mario mario ,Map& map ,Window& window ,int objectCounter);
  bool isLeftBehind(Mario mario);
  bool marioLeaveScreen(Mario mario);
  int getStartShotPoint();
  void setStartShotPoint(int startShot);
  int getScreenWidth();
  int getScreenHeight();
private:
  int screenHeight;
  int screenWidth;
  int startShotPoint = 0;
};

#endif
