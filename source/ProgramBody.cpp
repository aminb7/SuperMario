#include "ProgramBody.hpp"



ProgramBody::ProgramBody(string _fileName){
  fileName = _fileName;
}

void ProgramBody::handleStompingGoomba(Mario mario ,Map& map ,Camera camera ,Window& window ,int& goombaCounter){
  int objectCounter = -1;
  if(map.hitGoomba(map.findCranny(DOWN ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,DOWN ,objectCounter)){
    window.play_sound_effect(ENEMY_STOMP_SOUND);
    map.setGoombaDead(objectCounter);
  }
  map.goombasLastStand();
}

void ProgramBody::handleStompingKoopa(Mario mario ,Map& map ,Camera camera ,Window& window){
  int objectCounter = -1;
  if(map.hitKoopa(map.findCranny(DOWN ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,DOWN ,objectCounter)){
    window.play_sound_effect(ENEMY_STOMP_SOUND);
    map.setKoopaDead(objectCounter);
  }
}

void ProgramBody::handleHitingDeadKoopa(Mario& mario ,Map& map ,Camera& camera ,Window& window){
  int objectCounter = -1;
  if(map.hitKoopa(map.findCranny(FRONT ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,FRONT ,objectCounter)){
    if(map.getKoopas()[objectCounter].getSituation() == DYING && map.getKoopas()[objectCounter].getKickingSituation() != KICKED){
      map.kickingKoopas(objectCounter ,FRONT);
    }
  }
  if(map.hitKoopa(map.findCranny(BACK ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,BACK ,objectCounter)){
    if(map.getKoopas()[objectCounter].getSituation() == DYING && map.getKoopas()[objectCounter].getKickingSituation() != KICKED){
      map.kickingKoopas(objectCounter ,BACK);
    }
  }
}

void ProgramBody::handleStompingEnemies(Mario mario ,Map& map ,Camera camera ,Window& window ,int& goombaCounter){
  handleStompingGoomba(mario ,map ,camera ,window ,goombaCounter);
  handleStompingKoopa(mario ,map ,camera ,window);
  handleHitingDeadKoopa(mario ,map ,camera ,window);
}

void ProgramBody::handleHitingObjects(Camera& camera ,Mario& mario ,Map& map ,Window& window){
  hitingQustionBrick(camera ,mario ,map ,window);
  hitingBrick(camera ,mario ,map ,window);
  eatingMushrooms(camera ,mario ,map ,window);
}

void ProgramBody::eatingMushrooms(Camera& camera ,Mario& mario ,Map& map ,Window& window){
  int objectCounter = -1;
  if(map.eatRedMushroom(map.findCranny(UP ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,UP ,objectCounter)
   || map.eatRedMushroom(map.findCranny(FRONT ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,FRONT ,objectCounter)
    || map.eatRedMushroom(map.findCranny(DOWN ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,DOWN ,objectCounter)
     || map.eatRedMushroom(map.findCranny(BACK ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,BACK ,objectCounter)){
    mario.becomeBig();
    window.play_sound_effect(POWERUP_SOUND);
    map.setRedMushroomUnused(objectCounter);
  }
  if(map.eatHealthMushroom(map.findCranny(UP ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,UP ,objectCounter)
   || map.eatHealthMushroom(map.findCranny(FRONT ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,FRONT ,objectCounter)
    || map.eatHealthMushroom(map.findCranny(DOWN ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,DOWN ,objectCounter)
     || map.eatHealthMushroom(map.findCranny(BACK ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,BACK ,objectCounter)){
    mario.addLive();
    window.play_sound_effect(POWERUP_SOUND);
    map.setHealthMushroomUnused(objectCounter);
  }
}

void ProgramBody::hitingQustionBrick(Camera& camera ,Mario& mario ,Map& map ,Window& window){
  int objectCounter = -1;
  if(map.existQuestionBricks(map.findCranny(UP ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,UP ,objectCounter)){
    if(map.getQuestionBricks()[objectCounter].getInside() == FULL){
      map.givePowerUp(objectCounter ,mario ,window);
      camera.actQuestionTrembling(mario ,map ,window ,objectCounter);
    }
  }
}

void ProgramBody::hitingBrick(Camera& camera ,Mario& mario ,Map& map ,Window& window){
  int objectCounter = -1;
  if(map.existBlocks(map.findCranny(UP ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,UP ,objectCounter))
    if(map.getBlocks()[objectCounter].getType() == BRICK){
      if(mario.getsize() == NORMAL){
        camera.actBrickTrembling(mario ,map ,window ,objectCounter);
      }
      if(mario.getsize() == BIG)
        camera.actBrickSmashing(mario ,map ,window ,objectCounter);
    }
}

void ProgramBody::winMessage(Window& window ,Mario mario){
  window.clear();
  string coins = "coins : ";
  coins.append(to_string(mario.getCoins()));
  window.fill_rect(Rectangle(Point(0 ,0) ,window.get_width() ,window.get_height()) ,BLACK);
  window.show_text("YOU WIN!" ,Point(370, 200) ,WHITE ,MARIO_FONT ,50);
  window.show_text(coins ,Point(390, 250) ,WHITE ,MARIO_FONT ,40);
  window.update_screen();
  delay(5000);
}

void ProgramBody::loseMessage(Window& window){
  window.clear();
  window.fill_rect(Rectangle(Point(0 ,0) ,window.get_width() ,window.get_height()) ,BLACK);
  window.play_sound_effect(GAME_OVER_SOUND);
  window.show_text("YOU LOSE!", Point(370, 200), WHITE, MARIO_FONT, 40);
  window.update_screen();
  delay(5000);
}

void ProgramBody::hitingGoomba(Mario& mario ,Map& map ,Camera& camera ,Window& window){
  int objectCounter = -1;
  if(map.hitGoomba(map.findCranny(FRONT ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,FRONT ,objectCounter)
   || map.hitGoomba(map.findCranny(BACK ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,BACK ,objectCounter)){
    if(mario.getsize() == NORMAL && map.getGoombas()[objectCounter].getSituation() != DYING){
      window.play_sound_effect(MARIO_DEATH_SOUND);
      camera.marioActDying(mario ,map ,window);
      mario.die();
      map.resetMap();
      camera.setStartShotPoint(START_SHOT_POINT);
    }
    if(mario.getsize() == BIG && map.getGoombas()[objectCounter].getSituation() != DYING)
      mario.becomeNormal();
  }
}

void ProgramBody::hitingKoopa(Mario& mario ,Map& map ,Camera& camera ,Window& window){
  int objectCounter = -1;
  if(map.hitKoopa(map.findCranny(FRONT ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,FRONT ,objectCounter)
   || map.hitKoopa(map.findCranny(BACK ,mario.getPosition() ,mario.getWidth()) ,mario.getWidth() ,BACK ,objectCounter)){
    if(mario.getsize() == NORMAL && (map.getKoopas()[objectCounter].getSituation() != DYING)){
      window.play_sound_effect(MARIO_DEATH_SOUND);
      camera.marioActDying(mario ,map ,window);
      mario.die();
      map.resetMap();
      camera.setStartShotPoint(START_SHOT_POINT);
    }
    if(mario.getsize() == BIG && (map.getKoopas()[objectCounter].getSituation() != DYING))
      mario.becomeNormal();
  }
}

void ProgramBody::handleMariosDie(Mario& mario ,Map& map ,Camera& camera ,Window& window){
  if(mario.getPosition().y + mario.getHeight() >= camera.getScreenHeight()){
    window.play_sound_effect(MARIO_DEATH_SOUND);
    camera.marioActDying(mario ,map ,window);
    mario.die();
    map.resetMap();
    camera.setStartShotPoint(START_SHOT_POINT);
  }
  hitingGoomba(mario ,map ,camera ,window);
  hitingKoopa(mario ,map ,camera ,window);
}

void ProgramBody::handleChangingQuestions(int& questionCounter ,Map& map){
  if(questionCounter % 99 == 0)
    map.changQuestionBricksStyle();
  questionCounter++;
  if(questionCounter == 100)
    questionCounter = 1;
}

void ProgramBody::handleMarioJumping(Mario& mario ,Map& map ,Camera camera ,Window& window ,Event event){
  mario.setSituation(JUMPING);
  if(event.get_pressed_key() == 'w' && map.existAnObject(DOWN ,mario.getPosition() ,mario.getWidth() ,mario.getHeight()))
    window.play_sound_effect(JUMP_SOUND);
  if(!map.existAnObject(UP ,mario.getPosition() ,mario.getWidth() ,mario.getHeight()))
    mario.jump();
  else{
    mario.setSituation(STANDING);
    mario.setDistanceCovered(0);
  }
}

void ProgramBody::handleEnemiesFallings(Map& map ,Camera camera){
  map.goombasFalling(camera.getStartShotPoint() ,camera.getStartShotPoint() + camera.getScreenWidth());
  map.koopasFalling(camera.getStartShotPoint() ,camera.getStartShotPoint() + camera.getScreenWidth());
}

void ProgramBody::handleMushroomsFallings(Map& map ,Camera camera){
  map.redMushroomsFalling();
  map.healthMushroomsFalling();
}

void ProgramBody::handleMariosFalling(Mario& mario ,Map& map){
  if(!map.existAnObject(DOWN ,mario.getPosition() ,mario.getWidth() ,mario.getHeight()) && mario.getSituation() != JUMPING){
    mario.setSituation(STANDING);
    mario.fall();
    delay(10);
  }
}

void ProgramBody::handleFalling(Mario& mario ,Map& map ,Camera camera){
  handleMariosFalling(mario ,map);
  handleEnemiesFallings(map ,camera);
  handleMushroomsFallings(map ,camera);
}

void ProgramBody::handleMarioSliding(Mario& mario ,Camera camera ,Map& map ,Window& window){
  for(int i = 0 ;i < 7 ;i++){
    delay(30);
    if(map.existAnObject(mario.getDirection() ,mario.getPosition() ,mario.getWidth() ,mario.getHeight()))
      break;
    mario.slide();
    camera.showScreen(map ,window ,mario);
  }
}

void ProgramBody::handleFrames(Mario& mario ,int eventCounter){
  if(eventCounter % 3 == 0)
    mario.changWalkingStyle();
}

void ProgramBody::handleEnemysDirection(Map& map){
  map.handleGoombasDirections();
  map.handleKoopasDirections();
  map.handleRedMushroomsDirections();
  map.handleHealthMushroomsDirections();
}

void ProgramBody::handleEnemysMoving(Map& map ,Camera camera ,int& enemiesConuter){
  if(enemiesConuter % 30 == 0){
    map.handleGoombasMovings(camera.getStartShotPoint() ,camera.getStartShotPoint() + camera.getScreenWidth());
    map.handleKoopasMovings(camera.getStartShotPoint() ,camera.getStartShotPoint() + camera.getScreenWidth());
    map.handleMushroomsMovings();
  }
  enemiesConuter++;
  if(enemiesConuter == 100)
    enemiesConuter = 1;
}

void ProgramBody::handleDefualtTasks(Mario& mario ,Window& window ,Map& map ,Camera& camera ,int& enemiesConuter ,int& questionCounter ,int& coinCounter ,int& goombaCounter){
  if(camera.isLeftBehind(mario))
    camera.move();
  map.risingOfCoins(coinCounter);
  handleStompingEnemies(mario ,map ,camera ,window ,goombaCounter);
  handleHitingObjects(camera ,mario ,map ,window);
  handleEnemysDirection(map);
  handleEnemysMoving(map ,camera ,enemiesConuter);
  handleFalling(mario ,map ,camera);
  handleChangingQuestions(questionCounter ,map);
  handleMariosDie(mario ,map ,camera , window);
  camera.showScreen(map ,window ,mario);
}

void ProgramBody::handleKeyReleasing(Mario& mario ,Window& window ,Map map ,Camera camera){
  if(map.existAnObject(DOWN ,mario.getPosition() ,mario.getWidth() ,mario.getHeight()) && mario.getSituation() != STANDING)
   handleMarioSliding(mario ,camera ,map ,window);
  if(mario.getSituation() != JUMPING)
    mario.setSituation(STANDING);
  camera.showScreen(map ,window ,mario);
}

void ProgramBody::handleMoving(int direction ,int& eventCounter ,Window& window ,Camera& camera ,Map& map ,Mario& mario){
  if(direction == FRONT)
    mario.setDirection(RIGHT);
  else
    mario.setDirection(LEFT);
  handleFrames(mario , eventCounter);
  if((!camera.marioLeaveScreen(mario) || direction == FRONT) &&
   !map.existAnObject(direction ,mario.getPosition() ,mario.getWidth() ,mario.getHeight()))
    mario.move(direction);
  camera.showScreen(map ,window ,mario);
  eventCounter++;
}

void ProgramBody::gameLoop(Window& window ,Camera& camera, Map& map ,Mario& mario){
  Event event;
  camera.showScreen(map ,window ,mario);
  int eventCounter = 1 ,enemiesConuter = 1 ,questionCounter = 1 ,coinCounter = 1 ,goombaCounter;
  while(1){
    event = window.poll_for_event();
    if((event.get_pressed_key() == JUMP_KEY && map.existAnObject(DOWN ,mario.getPosition() ,mario.getWidth() ,mario.getHeight()))
     || mario.getSituation() == JUMPING){
      handleMarioJumping(mario ,map ,camera ,window ,event);
    }
    if(event.get_pressed_key() == FRONT_KEY)
      handleMoving(FRONT ,eventCounter ,window ,camera ,map ,mario);
    if(event.get_pressed_key() == BACK_KEY)
      handleMoving(BACK ,eventCounter ,window ,camera ,map ,mario);
    if(event.get_type() == Event::KEY_RELEASE)
      handleKeyReleasing(mario ,window ,map ,camera);
    handleDefualtTasks(mario ,window ,map ,camera ,enemiesConuter ,questionCounter ,coinCounter ,goombaCounter);
    if(event.get_pressed_key() == 'q')
      break;
    if(mario.getLives() == 0)
      throw Lose();
    if(map.marioReachFlag(mario.getPosition().x))
      throw Win();
  }
}

void ProgramBody::start(){
  Map map;
  map.makeMapReady(fileName);
  Mario mario(map.findMarioPosition());
  Camera camera(map.getPlot()[0].size() * DEFUALT_WIDTH ,map.getPlot().size() * DEFUALT_WIDTH);
  Window window(camera.getScreenWidth() , camera.getScreenHeight());
  window.play_music(THEME_MUSIC);
  try{
    gameLoop(window ,camera ,map ,mario);
  }
  catch (Win win){
    window.stop_music();
    winMessage(window ,mario);
  }
  catch (Lose lose){
    window.stop_music();
    loseMessage(window);
  }
}
