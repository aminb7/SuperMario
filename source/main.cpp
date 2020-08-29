#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../rsdllib/rsdl.hpp"
#include "ProgramBody.hpp"
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

using namespace std;


int main(int argc, char* argv[]) {
  ProgramBody programBody(argv[1]);
  programBody.start();
  return 0;
}
