
#include "testproject.h"
#include <iostream>

using namespace std;

/*
Create a function which simulates the game "rock, paper, scissors". The function takes the input of both players (rock, paper or scissors), first parameter from first player, second from second player. The function returns the result as such:

"Player 1 wins"
"Player 2 wins"
"TIE" (if both inputs are the same)
The rules of rock, paper, scissors, if not known:

Both players have to say either "rock", "paper" or "scissors" at the same time.
Rock beats scissors, paper beats rock, scissors beat paper.

rps("rock", "paper") ➞ "Player 2 wins"

rps("paper", "rock") ➞ "Player 1 wins"

rps("paper", "scissors") ➞ "Player 2 wins"

rps("scissors", "scissors") ➞ "TIE"

rps("scissors", "paper") ➞ "Player 1 wins"
*/

namespace
{
  enum Input
  {
    Invalid,
    Rock,
    Paper,
    Scissors
  };

  Input convertInput(std::string s) {
    if (s == "rock") {
      return Rock;
    } else if (s == "paper") {
      return Paper;
    } else if (s == "scissors") {
      return Scissors;
    } else {
      return Invalid;
    }
  }

  std::string rps(std::string s1, std::string s2) {
    Input o1 = convertInput(s1);
    Input o2 = convertInput(s2);
    
    if (o1 == o2)
    {
      return "TIE";
    }
    else if (o1 == Invalid || o2 == Invalid)
    {
      return "INVALID";
    }
    else
    {
      int winner;
      if (o1 == Paper)
      {
        winner = (o2 == Scissors) ? 2 : 1;
      }
      else if (o1 == Rock)
      {
        winner = (o2 == Paper) ? 2 : 1;
      }
      else if (o1 == Scissors)
      {
        winner = (o2 == Rock) ? 2 : 1;
      }
      else
      {
        return "INVALID";
      }
      
      return (winner == 1) ? "Player 1 wins" : "Player 2 wins";
    }
  }


  class PaperRockScissorsTests :public :: testing::Test
  {

  };

  TEST_F(PaperRockScissorsTests, BasicCase1)
  {
    std::string result = rps("rock", "paper");
    std::string expectedResult = "Player 2 wins";
    ASSERT_EQ(expectedResult, result);
  }


//rps("paper", "rock") ➞ "Player 1 wins"

//rps("paper", "scissors") ➞ "Player 2 wins"

//rps("scissors", "scissors") ➞ "TIE"

//rps("scissors", "paper") ➞ "Player 1 wins"

}
