#include "Camera.hpp"


int Camera::getStartShotPoint(){
  return startShotPoint;
}

void Camera::setStartShotPoint(int startShot){
  startShotPoint = startShot;
}

int Camera::getScreenWidth(){
  return screenWidth;
}

int Camera::getScreenHeight(){
  return screenHeight;
}

Camera::Camera(int _screenWidth, int _screenHeight){
  screenHeight = _screenHeight;
  if( _screenWidth < DEFUALT_SHOT_WIDTH)
    screenWidth = _screenWidth;
  else
    screenWidth = DEFUALT_SHOT_WIDTH;
}

void Camera::marioActDying(Mario& mario ,Map map ,Window& window){
  mario.setSituation(DEAD);
  for(int i = 0;i < 18 ;i++){
    mario.setPosition(Point(mario.getPosition().x ,mario.getPosition().y - 4));
    delay(30);
    showScreen(map ,window ,mario);
  }
  for(int i = 0;i < 25 ;i++){
    mario.setPosition(Point(mario.getPosition().x ,mario.getPosition().y + 6));
    delay(30);
    showScreen(map ,window ,mario);
  }
  delay(1000);
}

void Camera::actQuestionTrembling(Mario mario ,Map& map ,Window& window ,int objectCounter){
  map.tremblingQuestion(objectCounter ,UP);
  delay(20);
  showScreen(map ,window ,mario);
  map.tremblingQuestion(objectCounter ,DOWN);
  delay(20);
  showScreen(map ,window ,mario);
}

void Camera::actBrickTrembling(Mario mario ,Map& map ,Window& window ,int objectCounter){
  window.play_sound_effect(BUMP_SOUND);
  map.tremblingBrick(objectCounter ,UP);
  delay(20);
  showScreen(map ,window ,mario);
  map.tremblingBrick(objectCounter ,DOWN);
  delay(20);
  showScreen(map ,window ,mario);
}

void Camera::actBrickSmashing(Mario mario ,Map& map ,Window& window ,int objectCounter){
  window.play_sound_effect(BRICK_SMASH_SOUND);
  map.smashingBrick(objectCounter);
  delay(50);
  showScreen(map ,window ,mario);
  map.smashingBrick(objectCounter);
  delay(50);
  showScreen(map ,window ,mario);
  map.removeBrick(objectCounter);
}

void Camera::showBlocks(vector<Block> blocks, Window& win){
  string imageAddress;
  for(int i = 0; i < blocks.size(); i++){
    imageAddress = OBJECTS_ADDRESS;
    imageAddress.append(blocks[i].getType());
    win.draw_img(imageAddress, Rectangle(blocks[i].getPosition().x * DEFUALT_WIDTH - startShotPoint
      ,blocks[i].getPosition().y * DEFUALT_WIDTH ,DEFUALT_WIDTH ,DEFUALT_WIDTH ));
  }
}

void Camera::showQuestionBricks(vector<QuestionBrick> questionBricks ,Window& win){
  string imageAddress;
  for(int i = 0; i < questionBricks.size(); i++){
    imageAddress = OBJECTS_ADDRESS;
    imageAddress.append(questionBricks[i].getSituation());
    win.draw_img(imageAddress, Rectangle(questionBricks[i].getPosition().x * DEFUALT_WIDTH - startShotPoint
      ,questionBricks[i].getPosition().y * DEFUALT_WIDTH ,DEFUALT_WIDTH ,DEFUALT_WIDTH ));
  }
}

void Camera::showPipes(vector<Pipe> pipes ,Window& win){
  string imageAddress;
  for(int i = 0; i < pipes.size(); i++){
    imageAddress = OBJECTS_ADDRESS;
    imageAddress.append(pipes[i].getType());
    win.draw_img(imageAddress, Rectangle(pipes[i].getPosition().x *  DEFUALT_WIDTH - startShotPoint
      ,pipes[i].getPosition().y * DEFUALT_WIDTH ,DEFUALT_WIDTH ,DEFUALT_WIDTH ));
  }
}

void Camera::showFlag(vector<Flag> flag ,Window& win){
  string imageAddress;
  for(int i = 0; i < flag.size(); i++){
    imageAddress = OBJECTS_ADDRESS;
    imageAddress.append(FLAG_ADDRESS);
    imageAddress.append(flag[i].getType());
    imageAddress.append(".png");
    win.draw_img(imageAddress, Rectangle(flag[i].getPosition().x *  DEFUALT_WIDTH - startShotPoint
      ,flag[i].getPosition().y * DEFUALT_WIDTH ,DEFUALT_WIDTH ,DEFUALT_WIDTH ));
  }
}

void Camera::showCoins(vector<Coin> coins ,Window& win){
  string imageAddress;
  for(int i = 0; i < coins.size(); i++){
    imageAddress = OBJECTS_ADDRESS;
    imageAddress.append(COIN_ADDRESS);
    if(coins[i].getSituation() == USED){
      win.draw_img(imageAddress, Rectangle(coins[i].getPosition().x *  DEFUALT_WIDTH - startShotPoint
        ,coins[i].getPosition().y * DEFUALT_WIDTH ,DEFUALT_WIDTH ,DEFUALT_WIDTH ));
    }
  }
}

void Camera::showGoombas(vector<Goomba> goombas ,Window& win){
  string imageAddress;
  for(int i = 0; i < goombas.size(); i++){
    imageAddress = goombas[i].imageAddress();
    win.draw_img(imageAddress, Rectangle(goombas[i].getPosition().x - startShotPoint
      ,goombas[i].getPosition().y ,goombas[i].getWidth() ,goombas[i].getHeight() ));
  }
}

void Camera::showKoopas(vector<Koopa> koopas ,Window& win){
  string imageAddress;
  for(int i = 0; i < koopas.size(); i++){
    imageAddress = koopas[i].imageAddress();
    win.draw_img(imageAddress, Rectangle(koopas[i].getPosition().x - startShotPoint
      ,koopas[i].getPosition().y ,koopas[i].getWidth() ,koopas[i].getHeight() ));
  }
}

void Camera::showRedMushrooms(vector<RedMushroom> redMushrooms ,Window& win){
  string imageAddress;
  for(int i = 0; i < redMushrooms.size(); i++){
    imageAddress = OBJECTS_ADDRESS;
    imageAddress.append(RED_MUSHROOM_ADDRESS);
    win.draw_img(imageAddress, Rectangle(redMushrooms[i].getPosition().x - startShotPoint
      ,redMushrooms[i].getPosition().y ,redMushrooms[i].getWidth() ,redMushrooms[i].getHeight()));
  }
}

void Camera::showHealthMushrooms(vector<HealthMushroom> healthMushrooms ,Window& win){
  string imageAddress;
  for(int i = 0; i < healthMushrooms.size(); i++){
    imageAddress = OBJECTS_ADDRESS;
    imageAddress.append(HEALTH_MUSHROOM_ADDRESS);
    win.draw_img(imageAddress, Rectangle(healthMushrooms[i].getPosition().x - startShotPoint
      ,healthMushrooms[i].getPosition().y ,healthMushrooms[i].getWidth() ,healthMushrooms[i].getHeight()));
  }
}

void Camera::showObjects(Map map, Window& window){
  showBlocks(map.getBlocks() ,window);
  showQuestionBricks(map.getQuestionBricks() ,window);
  showPipes(map.getPipes() ,window);
  showFlag(map.getFlag() ,window);
  showCoins(map.getCoin() ,window);
  showRedMushrooms(map.getRedMushrooms() ,window);
  showHealthMushrooms(map.getHealthMushrooms() ,window);
  showGoombas(map.getGoombas() ,window);
  showKoopas(map.getKoopas() ,window);
}

void Camera::showMario(Mario mario ,Window& window){
  window.draw_img(mario.imageAddress() ,Rectangle(mario.getPosition().x - startShotPoint
   ,mario.getPosition().y ,mario.getWidth() ,mario.getHeight() ));
}

void Camera::showBackground(Window& window){
  window.draw_img(BACKGROUND_ADDRESS , Rectangle(-startShotPoint + (startShotPoint / screenWidth) * screenWidth
   ,0 ,screenWidth ,screenHeight));
   window.draw_img(BACKGROUND_ADDRESS , Rectangle(-startShotPoint + (startShotPoint / screenWidth + 1) * screenWidth
    ,0 ,screenWidth ,screenHeight));
}

void Camera::showCoinsAndLives(Mario mario ,Window& window){
  string coins = "coins";
  string lives = "lives";
  window.show_text(coins ,Point(320, 5) ,WHITE ,MARIO_FONT ,60);
  window.show_text(lives ,Point(520, 5) ,WHITE ,MARIO_FONT ,60);
  window.show_text(to_string(mario.getCoins()) ,Point(370, 70) ,WHITE ,MARIO_FONT ,50);
  window.show_text(to_string(mario.getLives()) ,Point(570, 70) ,WHITE ,MARIO_FONT ,50);
}

void Camera::showScreen(Map map ,Window& window ,Mario mario){
  showBackground(window);
  showObjects(map, window);
  showMario(mario ,window);
  showCoinsAndLives(mario ,window);
  window.update_screen();
}

void Camera::move(){
  startShotPoint += 5;
}

bool Camera::isLeftBehind(Mario mario){
  if(mario.getPosition().x >= startShotPoint + screenWidth / 2)
    return true;
  return false;
}

bool Camera::marioLeaveScreen(Mario mario){
  if(mario.getPosition().x < startShotPoint + 6)
    return true;
  return false;
}
