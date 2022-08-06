#include "testproject.h"

namespace
{
  class SimpleTest :public :: testing::Test
  {

  };

  TEST_F(SimpleTest, Returns0)
  {
    int i = 0;
    EXPECT_EQ(0, i);
  }
}
