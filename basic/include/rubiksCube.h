#ifndef rubiksCube_H
#define rubiksCube_H

enum class Direction {
  Clockwise = 1,
  CounterClockwise = -1
};

enum class Side {
  Left = 0,
  Back = 1,
  Top = 2,
  Front = 3,
  Right = 4,
  Down = 5
};

enum class Color
{
  Invalid = -1,
  Orange = 0,
  Blue = 1,
  Yellow = 2,
  White = 3,
  Red = 4,
  Green = 5
};

const char* toString(Direction d)
{
  return (d == Direction::Clockwise) ? "Clockwise" :
         (d == Direction::CounterClockwise) ? "Counter Clockwise" :
         "Error";
}

const char* toString(Side s)
{
  static const char* sideText[] = { "Left", "Back", "Top" "Front", "Right", "Down"};
  static const size_t sideTextCount = sizeof(sideText) / sizeof(const char*);
  size_t index = (size_t)s;

  if (index < sideTextCount)
  {
    return (sideText[index]);
  }
  else
  {
    return "Error";
  }
}

const char* toStringAbbrev(Side s)
{
  static const char* sideText[] = {"L", "B", "T" "F", "R", "D"};
  static const size_t sideTextCount = sizeof(sideText) / sizeof(const char*);
  size_t index = (size_t)s;

  if (index < sideTextCount)
  {
    return (sideText[index]);
  }
  else
  {
    return "e";
  }
}

const char* toString(Color c)
{
  static const char* colorText[] = {"Orange", "Blue", "Yellow" "White", "Red", "Green"};
  static const size_t colorTextCount = sizeof(colorText) / sizeof(const char*);
  size_t index = (size_t)c;

  if (index < colorTextCount)
  {
    return (colorText[index]);
  }
  else
  {
    return "Error";
  }
}

const char* toStringAbbrev(Color c)
{
  static const char* colorText[] = {"O", "B", "Y", "W", "R", "G"};
  static const size_t colorTextCount = sizeof(colorText) / sizeof(const char*);
  size_t index = (size_t)c;

  if (index < colorTextCount)
  {
    return (colorText[index]);
  }
  else
  {
    return "e";
  }
}

/*
  2x2
         *        +-------+
         *        | 8   9 | 
         *        | 11 10 |
         * +------+-------+-------+------+
         * | 1  2 | 12 13 | 19 16 | 6  7 |
         * | 0  3 | 15 14 | 18 17 | 5  4 | 
         * +------+-------+-------+------+
         *        | 22 23 |
         *        | 21 20 |
         *        +-------+
    T          2
  L F R B    0 3 4 1
    D          5
         *           +----------+
         *           | 18 19 20 | 
         *           | 23 22 21 |
         *           | 24 25 26 |
         * +---------+----------+----------+----------+
         * | 2  3  8 | 27 28 29 | 42 41 36 | 17 16 15 |
         * | 1  4  7 | 32 31 30 | 43 40 37 | 12 13 14 |
         * | 0  5  6 | 33 34 35 | 44 39 38 | 11 10  9 | 
         * +---------+----------+----------+----------+
         *           | 53 52 51 |
         *           | 48 49 50 |
         *           | 47 46 45 |
         *           +----------+
*/
class RubiksCube
{
public:
  RubiksCube()
  {
    initializeSide(Side::Left, Color::Orange);
    initializeSide(Side::Back, Color::Blue);
    initializeSide(Side::Top, Color::Yellow);
    initializeSide(Side::Front, Color::White);
    initializeSide(Side::Right, Color::Red);
    initializeSide(Side::Down, Color::Green);

    //const Color testCase1[] = 
    //{
      // Left
//      Color::Red, Color::Blue, Color::Blue, Color::Red, Color::Red, Color::Orange, Color::Yellow, Color::Green, Color::White,

      // Back
    //  Color::Green, Color::Green, Color::Green, Color::Blue, Color::Yellow, Color::Orange, 
    //}
  }

  static const int size = 3;
  static const int elementCount = size * size * 6;

/**
  * turn the specified side in the specified direction.
  * @param side which side of the cube to turn.
  * @param direction in which direction to turn the side.
  *  A value of 1 means clockwise, a value of -1 counter-clockwise.
  * @preconditions side&isin;{left,right,top,down,back,front}
  *      &and; direction&isin;{1,-1}
  */
void rotate(Side side, Direction direction) {
    switch (side) {
    case Side::Left:          // 'left - okay
        rotateRow(0, 1, 2, 3, direction);
        rotateRow(8, 12, 22, 4, direction);
        rotateRow(11, 15, 21, 7, direction);
        break;
    case Side::Back:  // 'back
        rotateRow(4, 5, 6, 7, direction);
        rotateRow(1, 21, 17, 9, direction);
        rotateRow(0, 20, 16, 8, direction);
        break;
    case Side::Top:           // 'top
        rotateRow(8, 9, 10, 11, direction);
        rotateRow(1, 6, 19, 12, direction);
        rotateRow(2, 7, 16, 13, direction);
        break;
    case Side::Front:         // 'front
        rotateRow(12, 13, 14, 15, direction);
        rotateRow(3, 11, 19, 23, direction);
        rotateRow(2, 10, 18, 22, direction);
        break;
    case Side::Right: // 'right
        rotateRow(16, 17, 18, 19, direction);
        rotateRow(9, 5, 23, 13, direction);
        rotateRow(10, 6, 20, 14, direction);
        break;
    case Side::Down:          // 'down
        rotateRow(20, 21, 22, 23, direction);
        rotateRow(5, 0, 15, 18, direction);
        rotateRow(4, 3, 14, 17, direction);
        break;

    default:
      // do nothing
      break;
    }

    printf("side = %s, direction = %s\n", toString(side), toString(direction));
} 

void rotateRow(int a, int b, int c, int d, Direction direction) 
{
  Color temp = elements_[a];
  if (direction == Direction::CounterClockwise)    // counter-clockwise
  {
      elements_[a] = elements_[b];
      elements_[b] = elements_[c];
      elements_[c] = elements_[d];
      elements_[d] = temp;
  }
  else if (direction == Direction::Clockwise)    // clockwise
  {
      elements_[a] = elements_[d];
      elements_[d] = elements_[c];
      elements_[c] = elements_[b];
      elements_[b] = temp;
  }
}

void printRow(size_t x1, size_t x2, size_t x3)
{
  printf("*            |  %s  %s  %s |\n",
         toStringAbbrev(element(x1)),
         toStringAbbrev(element(x2)),
         toStringAbbrev(element(x3)));
}

void printRow(size_t x1, size_t x2, size_t x3, size_t x4,
              size_t x5, size_t x6, size_t x7, size_t x8,
              size_t x9, size_t x10, size_t x11, size_t x12)
{
  printf("* |  %s  %s  %s |  %s  %s  %s |  %s  %s  %s |  %s  %s  %s |\n",
         toStringAbbrev(element(x1)),
         toStringAbbrev(element(x2)),
         toStringAbbrev(element(x3)),
         toStringAbbrev(element(x4)),
         toStringAbbrev(element(x5)),
         toStringAbbrev(element(x6)),
         toStringAbbrev(element(x7)),
         toStringAbbrev(element(x8)),
         toStringAbbrev(element(x9)),
         toStringAbbrev(element(x10)),
         toStringAbbrev(element(x11)),
         toStringAbbrev(element(x12))
         );
}

void printState()
{
  /*
  for (size_t i = 0; i < elementCount; i++)
  {
    printf("%u: %d\n", i, (int)elements_[i]);
  }*/

  printf("*            +----------+\n");
  printRow(18, 19, 20);
  printRow(23, 22, 21);
  printRow(24, 25, 26);

  printf("* +----------+----------+----------+----------+\n");
  printRow(2,3,8,27,28,29,42,41,36,17,16,15);
  printRow(1,4,7,32,31,30,43,40,37,12,13,14);
  printRow(0,5,6,33,34,35,44,39,38,11,10,9);
  printf("* +----------+----------+----------+----------+\n");

  printRow(53,52,51);
  printRow(48,49,50);
  printRow(47,46,45);

  printf("*            +----------+\n");
}

void initializeSide(Side s, Color c)
{
  size_t index = ((size_t)s) * 9;
  for (size_t i = index; i < index + 9; i++)
  {
    elements_[i] = c;
  }
}

private:
  Color element(size_t index)
  {
    static const size_t elementCount = sizeof(elements_) / sizeof(Color);
    if (index < elementCount)
    {
      return elements_[index];
    }
    else
    {
      return Color::Invalid;
    }
  }

  Color elements_[elementCount];
};

#endif
