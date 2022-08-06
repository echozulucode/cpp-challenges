#include "testproject.h"

int main(int argc, char** argv)
{
  setbuf(stdout, NULL);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
