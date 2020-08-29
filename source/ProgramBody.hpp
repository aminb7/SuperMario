#ifndef PROGRAM_BODY
#define PROGRAM_BODY
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../rsdllib/rsdl.hpp"
#include "Map.hpp"
#include "Camera.hpp"
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

#define JUMP_KEY 'W'
#define FRONT_KEY 'D'
#define BACK_KEY 'W'
#define ENEMY_STOMP_SOUND "sounds/enemy-stomp.wav"
#define FRONT 1
#define BACK -1
#define UP 2
#define DOWN -2
#define RIGHT "right"
#define LEFT "left"
#define DYING "dead"
#define UNKICKED 1
#define KICKED -1
#define POWERUP_SOUND "sounds/powerup.wav"
#define FULL 1
#define EMPTY -1
#define BRICK "brick.png"
#define NORMAL "normal"
#define BIG "big"
#define STANDING "standing"
#define JUMPING "jumping"
#define SLIDING "sliding"
#define DEAD "dead"
#define GAME_OVER_SOUND "sounds/gameover.wav"
#define MARIO_FONT "mario_font.ttf"
#define MARIO_DEATH_SOUND "sounds/mario-death.wav"
#define START_SHOT_POINT 0
#define JUMP_SOUND "sounds/jump-small.wav"
#define THEME_MUSIC "sounds/theme-music.mp3"
#define DEFUALT_WIDTH 32
#define JUMP_KEY 'w'
#define FRONT_KEY 'd'
#define BACK_KEY 'a'

using namespace std;

class Win{};

class Lose{};

class ProgramBody{
public:
  ProgramBody(string _fileName);
  void start();
  void gameLoop(Window& window ,Camera& camera, Map& map ,Mario& mario);
  void handleMoving(int direction ,int& eventCounter ,Window& window ,Camera& camera ,Map& map ,Mario& mario);
  void handleFrames(Mario& mario ,int eventCounter);
  void handleKeyReleasing(Mario& mario ,Window& window ,Map map ,Camera camera);
  void handleDefualtTasks(Mario& mario ,Window& window ,Map& map ,Camera& camera ,int& enemiesConuter ,int& questionCounter ,int& coinCounter ,int& goombaCounter);
  void handleEnemysDirection(Map& map);
  void handleEnemysMoving(Map& map ,Camera camera ,int& enemiesConuter);
  void handleMarioSliding(Mario& mario ,Camera camera ,Map& map ,Window& window);
  void handleFalling(Mario& mario ,Map& map ,Camera camera);
  void handleMariosFalling(Mario& mario ,Map& map);
  void handleEnemiesFallings(Map& map ,Camera camera);
  void handleMushroomsFallings(Map& map ,Camera camera);
  void handleMarioJumping(Mario& mario ,Map& map ,Camera camera ,Window& window ,Event event);
  void handleChangingQuestions(int& questionCounter ,Map& map);
  void handleMariosDie(Mario& mario ,Map& map ,Camera& camera ,Window& window);
  void winMessage(Window& window ,Mario mario);
  void loseMessage(Window& window);
  void handleHitingObjects(Camera& camera ,Mario& mario ,Map& map ,Window& window);
  void hitingQustionBrick(Camera& camera ,Mario& mario ,Map& map ,Window& window);
  void hitingBrick(Camera& camera ,Mario& mario ,Map& map ,Window& window);
  void eatingMushrooms(Camera& camera ,Mario& mario ,Map& map ,Window& window);
  void handleStompingEnemies(Mario mario ,Map& map ,Camera camera ,Window& window ,int& goombaCounter);
  void handleStompingGoomba(Mario mario ,Map& map ,Camera camera ,Window& window ,int& goombaCounter);
  void handleStompingKoopa(Mario mario ,Map& map ,Camera camera ,Window& window);
  void hitingGoomba(Mario& mario ,Map& map ,Camera& camera ,Window& window);
  void hitingKoopa(Mario& mario ,Map& map ,Camera& camera ,Window& window);
  void handleHitingDeadKoopa(Mario& mario ,Map& map ,Camera& camera ,Window& window);
private:
  string fileName;
};

#endif
