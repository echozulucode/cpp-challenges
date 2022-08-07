#include "testproject.h"
#include <iostream>
#include "rubiksCube.h"

using namespace std;

namespace
{
  class RubiksCubeTests :public :: testing::Test
  {

  };

  TEST_F(RubiksCubeTests, BasicCase1)
  {
    RubiksCube cube;
    cube.printState();
    cube.rotate(Side::Left, Direction::Clockwise);
    cube.printState();
  }
}
