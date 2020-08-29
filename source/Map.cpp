#include "Map.hpp"



vector<string> Map::getPlot(){
  return plot;
}

vector<Block> Map::getBlocks(){
  return blocks;
}

vector<QuestionBrick> Map::getQuestionBricks(){
  return questionBricks;
}

vector<Pipe> Map::getPipes(){
  return pipes;
}

vector<Flag> Map::getFlag(){
  return flag;
}

vector<Coin> Map::getCoin(){
  return coins;
}

vector<Goomba> Map::getGoombas(){
  return goombas;
}

vector<Koopa> Map::getKoopas(){
  return koopas;
}

vector<RedMushroom> Map::getRedMushrooms(){
  return redMushrooms;
}

vector<HealthMushroom> Map::getHealthMushrooms(){
  return healthMushrooms;
}

void Map::givePowerUp(int objectCounter ,Mario& mario ,Window& window){
  questionBricks[objectCounter].setInside(EMPTY);
  questionBricks[objectCounter].setSituation(QUESTION_4);
  if(questionBricks[objectCounter].getType() == 1){
    coins.push_back(Point(questionBricks[objectCounter].getPosition().x ,questionBricks[objectCounter].getPosition().y - 1));
    window.play_sound_effect(COIN_SOUND);
    mario.addCoin();
  }
  if(questionBricks[objectCounter].getType() == 2){
    window.play_sound_effect(POWERUP_APEARS_SOUND);
    redMushrooms.push_back(RedMushroom(Point(questionBricks[objectCounter].getPosition().x * DEFUALT_WIDTH ,(questionBricks[objectCounter].getPosition().y - 1) * DEFUALT_WIDTH)));
  }
  if(questionBricks[objectCounter].getType() == 3){
    window.play_sound_effect(POWERUP_APEARS_SOUND);
    healthMushrooms.push_back(HealthMushroom(Point(questionBricks[objectCounter].getPosition().x * DEFUALT_WIDTH ,(questionBricks[objectCounter].getPosition().y - 1) * DEFUALT_WIDTH)));
  }
}

void Map::risingOfCoins(int& coinCounter){
  if(coinCounter % 7 == 0){
    for(int i = 0 ;i < coins.size() ;i++){
      if(coins[i].getSituation() == USED){
        coins[i].rise();
      }
    }
  }
  coinCounter++;
  if(coinCounter == 100)
    coinCounter = 1;
}

bool Map::marioReachFlag(int x){
  if(x >= flag[0].getPosition().x * DEFUALT_WIDTH)
    return true;
  return false;
}

void Map::freeMap(){
  blocks.clear();
  questionBricks.clear();
  pipes.clear();
  goombas.clear();
  koopas.clear();
  flag.clear();
  redMushrooms.clear();
  healthMushrooms.clear();
}

void Map::resetMap(){
  freeMap();
  fillMap();
}

void Map::changQuestionBricksStyle(){
  for(int i = 0; i < questionBricks.size(); i++){
    if(questionBricks[i].getInside() != EMPTY)
      questionBricks[i].changStyle();
  }
}

void Map::readMapData(string fileName){
  ifstream mapData(fileName);
  string line;
  if (mapData.is_open())
  {
    while ( getline (mapData,line) )
    {
      plot.push_back(line);
    }
    mapData.close();
  }
  else cout << "Unable to open file";
}

string Map::findPipeType(Point position){
  if(plot[position.y - 1][position.x] != PIPE){
    if(plot[position.y][position.x + 1] == PIPE)
      return HEAD_LEFT_PIPE;
    else
      return HEAD_RIGHT_PIPE;
  }
  else{
    if(plot[position.y][position.x + 1] == PIPE)
      return LEFT_PIPE;
    else
      return RIGHT_PIPE;
  }
}

Point Map::findMarioPosition(){
  for(int x = 0; x < plot[0].size() ;x++){
    for(int y = 0; y < plot.size() ;y++){
      if(plot[y][x] == MARIO)
        return Point(x * DEFUALT_WIDTH ,y * DEFUALT_WIDTH);
    }
  }
}

void Map::addBlocks(char object ,Point _position){
  if(object == BLOCK_TYPE1)
    blocks.push_back(Block(_position ,BRICK));
  if(object == BLOCK_TYPE2)
    blocks.push_back(Block(_position ,BLOCK));
  if(object == BLOCK_TYPE3)
    blocks.push_back(Block(_position ,CLAY));
}

void Map::addQuestionBricks(char object ,Point _position){
  if(object == QUESTION_BRICK_TYPE1)
    questionBricks.push_back(QuestionBrick(_position ,1));
  if(object == QUESTION_BRICK_TYPE2)
    questionBricks.push_back(QuestionBrick(_position ,2));
  if(object == QUESTION_BRICK_TYPE3)
    questionBricks.push_back(QuestionBrick(_position ,3));
}

void Map::addPipe(char object ,Point _position){
  if(object == PIPE)
    pipes.push_back(Pipe(_position ,findPipeType(_position)));
}

void Map::addFlag(char object ,Point _position ,char previous){
  if(object == FLAG){
    if(previous == FLAG)
      flag.push_back(Flag(_position ,FLAG_BODY));
    if(previous != FLAG)
      flag.push_back(Flag(_position ,FLAG_HEAD));
  }
}

void Map::addGoomba(char object ,Point _position){
  if(object == GOOMBA)
    goombas.push_back(Goomba(_position));
}

void Map::addKoopa(char object ,Point _position){
  if(object == KOOPA)
    koopas.push_back(Koopa(_position));
}

void Map::fillMap() {
  for(int x = 0; x < plot[0].size() ;x++){
    for(int y = 1; y < plot.size() ;y++){
      addBlocks(plot[y][x] ,Point(x ,y));
      addQuestionBricks(plot[y][x] ,Point(x ,y));
      addPipe(plot[y][x] ,Point(x ,y));
      addFlag(plot[y][x] ,Point(x ,y) ,plot[y - 1][x]);
      addGoomba(plot[y][x] ,Point(x * DEFUALT_WIDTH ,y * DEFUALT_WIDTH));
      addKoopa(plot[y][x] ,Point(x * DEFUALT_WIDTH,y * DEFUALT_WIDTH));
    }
  }
}

void Map::makeMapReady(string fileName){
  readMapData(fileName);
  fillMap();
}

Point Map::findCranny(int direction ,Point position ,int width){
  Point cranny(0 ,0);
  if(direction == UP){
      cranny.x = position.x;
      cranny.y = position.y - 3;
  }
  if(direction == FRONT){
      cranny.x = position.x + width + 1;
      cranny.y = position.y;
  }
  if(direction == DOWN){
      cranny.x = position.x;
      cranny.y = position.y + width + 1;
  }
  if(direction == BACK){
      cranny.x = position.x - 3;
      cranny.y = position.y;
  }
  return cranny;
}

bool Map::existAnObject(int direction ,Point position ,int width ,int height){
  Point cranny(0 ,0);
  cranny = findCranny(direction ,position ,width);
  int length = width ,objectCounter = 0;
  return  existQuestionBricks(cranny ,length ,direction ,objectCounter)
    || existPipes(cranny ,length ,direction ,objectCounter) || existBlocks(cranny ,length ,direction ,objectCounter);
}

bool Map::checkLength(int x1 ,int x2 ,int y1 ,int y2){
  for(int i = y1 + 6 ;i <= y2 - 6 ;i++)
    if(i > x1 && i < x2)
      return true;
  return false;
}

bool Map::existPipes(Point cranny ,int length ,int direction ,int& objectCounter){
  if(direction == UP || direction == DOWN){
    for(int i = 0 ;i < pipes.size() ;i++){
      if(cranny.y >= pipes[i].getPosition().y * DEFUALT_WIDTH && cranny.y <= pipes[i].getPosition().y * DEFUALT_WIDTH + DEFUALT_WIDTH)
        if(checkLength(pipes[i].getPosition().x * DEFUALT_WIDTH ,pipes[i].getPosition().x * DEFUALT_WIDTH + DEFUALT_WIDTH ,cranny.x ,cranny.x + length))
          return true;
    }
  }
  if(direction == FRONT || direction == BACK){
    for(int i = 0 ;i < pipes.size() ;i++){
      if(cranny.x >= pipes[i].getPosition().x * DEFUALT_WIDTH &&  cranny.x <= pipes[i].getPosition().x * DEFUALT_WIDTH + DEFUALT_WIDTH)
        if(checkLength(pipes[i].getPosition().y * DEFUALT_WIDTH ,pipes[i].getPosition().y * DEFUALT_WIDTH + DEFUALT_WIDTH ,cranny.y ,cranny.y + length))
          return true;
    }
  }
  return false;
}

bool Map::hitAnEnemy(int direction ,int enemyType ,Point position ,int width ,int height){
  Point cranny(0 ,0);
  cranny = findCranny(direction ,position ,width);
  int length = width ,objectCounter = 0;
  if(enemyType == _GOOMBA)
    return hitGoomba(cranny ,length ,direction ,objectCounter);
  if(enemyType == _KOOPA)
    return hitKoopa(cranny ,length ,direction ,objectCounter);
  if(enemyType == _GOOMBA + _KOOPA)
    return hitGoomba(cranny ,length ,direction ,objectCounter) || hitKoopa(cranny ,length ,direction ,objectCounter);
}

bool Map::hitGoomba(Point cranny ,int length ,int direction ,int& objectCounter){
  if(direction == UP || direction == DOWN){
    for(int i = 0 ;i < goombas.size() ;i++){
      if(cranny.y >= goombas[i].getPosition().y && cranny.y <= goombas[i].getPosition().y + DEFUALT_WIDTH)
        if(checkLength(goombas[i].getPosition().x ,goombas[i].getPosition().x + DEFUALT_WIDTH ,cranny.x ,cranny.x + length)){
          objectCounter = i;
          return true;
        }
    }
  }
  if(direction == FRONT || direction == BACK){
    for(int i = 0 ;i < goombas.size() ;i++){
      if(cranny.x >= goombas[i].getPosition().x &&  cranny.x <= goombas[i].getPosition().x + DEFUALT_WIDTH)
        if(checkLength(goombas[i].getPosition().y ,goombas[i].getPosition().y + DEFUALT_WIDTH ,cranny.y ,cranny.y + length)){
          objectCounter = i;
          return true;
        }
    }
  }
  return false;
}

bool Map::hitKoopa(Point cranny ,int length ,int direction ,int& objectCounter){
  if(direction == UP || direction == DOWN){
    for(int i = 0 ;i < koopas.size() ;i++){
      if(cranny.y >= koopas[i].getPosition().y && cranny.y <= koopas[i].getPosition().y + DEFUALT_WIDTH)
        if(checkLength(koopas[i].getPosition().x ,koopas[i].getPosition().x + DEFUALT_WIDTH ,cranny.x ,cranny.x + length)){
          objectCounter = i;
          return true;
        }
    }
  }
  if(direction == FRONT || direction == BACK){
    for(int i = 0 ;i < koopas.size() ;i++){
      if(cranny.x >= koopas[i].getPosition().x &&  cranny.x <= koopas[i].getPosition().x + DEFUALT_WIDTH)
        if(checkLength(koopas[i].getPosition().y ,koopas[i].getPosition().y + DEFUALT_WIDTH ,cranny.y ,cranny.y + length)){
          objectCounter = i;
          return true;
        }
    }
  }
  return false;
}

bool Map::eatRedMushroom(Point cranny ,int length ,int direction ,int& objectCounter){
  if(direction == UP || direction == DOWN){
    for(int i = 0 ;i < redMushrooms.size() ;i++){
      if(cranny.y >= redMushrooms[i].getPosition().y && cranny.y <= redMushrooms[i].getPosition().y + DEFUALT_WIDTH)
        if(checkLength(redMushrooms[i].getPosition().x ,redMushrooms[i].getPosition().x + DEFUALT_WIDTH ,cranny.x ,cranny.x + length)){
          objectCounter = i;
          return true;
        }
    }
  }
  if(direction == FRONT || direction == BACK){
    for(int i = 0 ;i < redMushrooms.size() ;i++){
      if(cranny.x >= redMushrooms[i].getPosition().x &&  cranny.x <= redMushrooms[i].getPosition().x + DEFUALT_WIDTH)
        if(checkLength(redMushrooms[i].getPosition().y ,redMushrooms[i].getPosition().y + DEFUALT_WIDTH ,cranny.y ,cranny.y + length)){
          objectCounter = i;
          return true;
        }
    }
  }
  return false;
}

void Map::handleGoombasDirections(){
  for(int i = 0 ;i < goombas.size() ;i++){
    if(goombas[i].getDirection() == LEFT && existAnObject(BACK ,goombas[i].getPosition() ,goombas[i].getWidth() , goombas[i].getHeight())){
      goombas[i].setDirection(RIGHT);
    }
  }
  for(int i = 0 ;i < goombas.size() ;i++){
    if(goombas[i].getDirection() == RIGHT && existAnObject(FRONT ,goombas[i].getPosition() ,goombas[i].getWidth() , goombas[i].getHeight())){
      goombas[i].setDirection(LEFT);
    }
  }
}

void Map::handleKoopasDirections(){
  for(int i = 0 ;i < koopas.size() ;i++){
    if(koopas[i].getDirection() == LEFT && existAnObject(BACK ,koopas[i].getPosition() ,koopas[i].getWidth() , koopas[i].getHeight()))
      koopas[i].setDirection(RIGHT);
  }
  for(int i = 0 ;i < koopas.size() ;i++){
    if(koopas[i].getDirection() == RIGHT && existAnObject(FRONT ,koopas[i].getPosition() ,koopas[i].getWidth() , koopas[i].getHeight()))
      koopas[i].setDirection(LEFT);
  }
}

void Map::handleGoombasMovings(int start ,int end){
  for(int i = 0 ;i < goombas.size() ;i++){
    if(goombas[i].getPosition().x >= start && goombas[i].getPosition().x <= end && goombas[i].getSituation() != DYING)
      goombas[i].move();
    goombas[i].changWalkingStyle();
  }
}

void Map::handleKoopasMovings(int start ,int end){
  for(int i = 0 ;i < koopas.size() ;i++){
    if(koopas[i].getPosition().x >= start && koopas[i].getPosition().x <= end && koopas[i].getSituation() != DYING){
      koopas[i].move();
      koopas[i].changWalkingStyle();
    }
    if(koopas[i].getSituation() == DYING && koopas[i].getKickingSituation() == KICKED)
      koopas[i].kick();
  }
}

void Map::handleRedMushroomsDirections(){
  for(int i = 0 ;i < redMushrooms.size() ;i++){
    if(redMushrooms[i].getDirection() == LEFT && existAnObject(BACK ,redMushrooms[i].getPosition() ,redMushrooms[i].getWidth() , redMushrooms[i].getHeight())){
      redMushrooms[i].setDirection(RIGHT);
    }
  }
  for(int i = 0 ;i < redMushrooms.size() ;i++){
    if(redMushrooms[i].getDirection() == RIGHT && existAnObject(FRONT ,redMushrooms[i].getPosition() ,redMushrooms[i].getWidth() , redMushrooms[i].getHeight())){
      redMushrooms[i].setDirection(LEFT);
    }
  }
}

bool Map::eatHealthMushroom(Point cranny ,int length ,int direction ,int& objectCounter){
  if(direction == UP || direction == DOWN){
    for(int i = 0 ;i < healthMushrooms.size() ;i++){
      if(cranny.y >= healthMushrooms[i].getPosition().y && cranny.y <= healthMushrooms[i].getPosition().y + DEFUALT_WIDTH)
        if(checkLength(healthMushrooms[i].getPosition().x ,healthMushrooms[i].getPosition().x + DEFUALT_WIDTH ,cranny.x ,cranny.x + length)){
          objectCounter = i;
          return true;
        }
    }
  }
  if(direction == FRONT || direction == BACK){
    for(int i = 0 ;i < healthMushrooms.size() ;i++){
      if(cranny.x >= healthMushrooms[i].getPosition().x &&  cranny.x <= healthMushrooms[i].getPosition().x + DEFUALT_WIDTH)
        if(checkLength(healthMushrooms[i].getPosition().y ,healthMushrooms[i].getPosition().y + DEFUALT_WIDTH ,cranny.y ,cranny.y + length)){
          objectCounter = i;
          return true;
        }
    }
  }
  return false;
}

void Map::handleMushroomsMovings(){
  for(int i = 0 ;i < redMushrooms.size() ;i++){
    redMushrooms[i].move();
  }
  for(int i = 0 ;i < healthMushrooms.size() ;i++){
    healthMushrooms[i].move();
  }
}

void Map::goombasFalling(int start ,int end){
  for(int i = 0 ;i < goombas.size() ;i++){
    if(!existAnObject(DOWN ,goombas[i].getPosition() ,goombas[i].getWidth() ,goombas[i].getHeight())
     && goombas[i].getPosition().x >= start && goombas[i].getPosition().x <= end)
      goombas[i].fall();
  }
}

bool Map::existQuestionBricks(Point cranny ,int length ,int direction ,int& objectCounter){
  if(direction == UP || direction == DOWN){
    for(int i = 0 ;i < questionBricks.size() ;i++){
      if(cranny.y >= questionBricks[i].getPosition().y * DEFUALT_WIDTH && cranny.y <= questionBricks[i].getPosition().y * DEFUALT_WIDTH + DEFUALT_WIDTH)
        if(checkLength(questionBricks[i].getPosition().x * DEFUALT_WIDTH ,questionBricks[i].getPosition().x * DEFUALT_WIDTH + DEFUALT_WIDTH ,cranny.x ,cranny.x + length)){
          objectCounter = i;
          return true;
        }
    }
  }
  if(direction == FRONT || direction == BACK){
    for(int i = 0 ;i < questionBricks.size() ;i++){
      if(cranny.x >= questionBricks[i].getPosition().x * DEFUALT_WIDTH &&  cranny.x <= questionBricks[i].getPosition().x * DEFUALT_WIDTH + DEFUALT_WIDTH)
        if(checkLength(questionBricks[i].getPosition().y * DEFUALT_WIDTH ,questionBricks[i].getPosition().y * DEFUALT_WIDTH + DEFUALT_WIDTH ,cranny.y ,cranny.y + length)){
          objectCounter = i;
          return true;
        }
    }
  }
  return false;
}

void Map::koopasFalling(int start ,int end){
  for(int i = 0 ;i < koopas.size() ;i++){
    if(!existAnObject(DOWN ,koopas[i].getPosition() ,koopas[i].getWidth() ,koopas[i].getHeight())
     && koopas[i].getPosition().x >= start && koopas[i].getPosition().x <= end)
      koopas[i].fall();
  }
}

void Map::redMushroomsFalling(){
  for(int i = 0 ;i < redMushrooms.size() ;i++){
    if(!existAnObject(DOWN ,redMushrooms[i].getPosition() ,redMushrooms[i].getWidth() ,redMushrooms[i].getHeight()))
      redMushrooms[i].fall();
  }
}

void Map::healthMushroomsFalling(){
  for(int i = 0 ;i < healthMushrooms.size() ;i++){
    if(!existAnObject(DOWN ,healthMushrooms[i].getPosition() ,healthMushrooms[i].getWidth() ,healthMushrooms[i].getHeight()))
      healthMushrooms[i].fall();
  }
}

void Map::handleHealthMushroomsDirections(){
  for(int i = 0 ;i < healthMushrooms.size() ;i++){
    if(healthMushrooms[i].getDirection() == LEFT && existAnObject(BACK ,healthMushrooms[i].getPosition() ,healthMushrooms[i].getWidth() , healthMushrooms[i].getHeight())){
      healthMushrooms[i].setDirection(RIGHT);
    }
  }
  for(int i = 0 ;i < healthMushrooms.size() ;i++){
    if(healthMushrooms[i].getDirection() == RIGHT && existAnObject(FRONT ,healthMushrooms[i].getPosition() ,healthMushrooms[i].getWidth() , healthMushrooms[i].getHeight())){
      healthMushrooms[i].setDirection(LEFT);
    }
  }
}

void Map::removeBrick(int objectCounter){
  blocks.erase(blocks.begin() + objectCounter);
}

void Map::tremblingQuestion(int objectCounter ,int direction){
  if(direction == UP)
    questionBricks[objectCounter].setPosition(Point(questionBricks[objectCounter].getPosition().x ,questionBricks[objectCounter].getPosition().y - 1));
  if(direction == DOWN)
    questionBricks[objectCounter].setPosition(Point(questionBricks[objectCounter].getPosition().x ,questionBricks[objectCounter].getPosition().y + 1));
}

void Map::tremblingBrick(int objectCounter ,int direction){
  if(direction == UP)
    blocks[objectCounter].setPosition(Point(blocks[objectCounter].getPosition().x ,blocks[objectCounter].getPosition().y - 1));
  if(direction == DOWN)
    blocks[objectCounter].setPosition(Point(blocks[objectCounter].getPosition().x ,blocks[objectCounter].getPosition().y + 1));
}

void Map::removeGoomba(int objectCounter){
  goombas.erase(goombas.begin() + objectCounter);
}

void Map::removeKoopa(int objectCounter){
  koopas.erase(koopas.begin() + objectCounter);
}

void Map::smashingBrick(int objectCounter){
  blocks[objectCounter].setSituation(SMASHED);
  blocks[objectCounter].setPosition(Point(blocks[objectCounter].getPosition().x ,blocks[objectCounter].getPosition().y - 1));
}

void Map::setRedMushroomUnused(int objectCounter){
  redMushrooms.erase(redMushrooms.begin() + objectCounter);
}

void Map::setHealthMushroomUnused(int objectCounter){
  healthMushrooms.erase(healthMushrooms.begin() + objectCounter);
}

void Map::setGoombaDead(int objectCounter){
  goombas[objectCounter].setSituation(DYING);
}

void Map::setKoopaDead(int objectCounter){
  koopas[objectCounter].setSituation(DYING);
}

void Map::goombasLastStand(){
  for(int i = 0;i < goombas.size() ;i++){
    if(goombas[i].getSituation() == DYING)
      goombas[i].addLastStand();
    if(goombas[i].getLastStand() == DEFUALT_GOOMBA_LIFE)
      goombas.erase(goombas.begin() + i);
  }
}

bool Map::existBlocks(Point cranny ,int length ,int direction ,int& objectCounter){
  if(direction == UP || direction == DOWN){
    for(int i = 0 ;i < blocks.size() ;i++){
      if(cranny.y >= blocks[i].getPosition().y * DEFUALT_WIDTH && cranny.y <= blocks[i].getPosition().y * DEFUALT_WIDTH + DEFUALT_WIDTH)
        if(checkLength(blocks[i].getPosition().x * DEFUALT_WIDTH ,blocks[i].getPosition().x * DEFUALT_WIDTH + DEFUALT_WIDTH ,cranny.x ,cranny.x + length)){
          objectCounter = i;
          return true;
        }
    }
  }
  if(direction == FRONT || direction == BACK){
    for(int i = 0 ;i < blocks.size() ;i++){
      if(cranny.x >= blocks[i].getPosition().x * DEFUALT_WIDTH && cranny.x <= blocks[i].getPosition().x * DEFUALT_WIDTH + DEFUALT_WIDTH)
        if(checkLength(blocks[i].getPosition().y * DEFUALT_WIDTH ,blocks[i].getPosition().y * DEFUALT_WIDTH + DEFUALT_WIDTH ,cranny.y ,cranny.y + length)){
          objectCounter = i;
          return true;
        }
    }
  }
  return false;
}

void Map::kickingKoopas(int objectCounter ,int direction){
  koopas[objectCounter].setKickingSituation(KICKED);
  if(direction == FRONT)
    koopas[objectCounter].setDirection(RIGHT);
  if(direction == BACK)
    koopas[objectCounter].setDirection(LEFT);
}
