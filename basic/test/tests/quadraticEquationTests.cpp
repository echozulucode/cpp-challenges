#include "testproject.h"
#include <iostream>

using namespace std;

/*
Create a function to find only the root value of x in any quadratic equation ax^2 + bx + c. The function will take three arguments:

a as the coefficient of x^2
b as the coefficient of x
c as the constant term

quadraticEquation(1, 2, -3) ➞ 1

quadraticEquation(2, -7, 3) ➞ 3

quadraticEquation(1, -12, -28) ➞ 14
*/

namespace
{
  int quadraticEquation(int a, int b, int c) 
  {
    int discriminant = b*b - 4*a*c;
    double x1;
    double x2;
    
    cout << "discriminant = " << discriminant << endl;

    if (discriminant > 0) 
    {
        x1 = (-b + std::sqrt(discriminant)) / (2*a);
        x2 = (-b - std::sqrt(discriminant)) / (2*a);

        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }  
    else if (discriminant == 0) {
        x1 = -b/(2*a);
        cout << "x1 = " << x1 << endl;
    }
    else 
    {
        double realPart = -b/(2*a);
        double imaginaryPart = std::sqrt(-discriminant)/(2*a);
        cout << "Roots are complex and different."  << endl;
        cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
    }
    
    return (int)x1;
  }

  class QuadraticEquationTests :public :: testing::Test
  {

  };

  TEST_F(QuadraticEquationTests, BasicCase1)
  {
    int result = quadraticEquation(1,2,-3);
    int expectedResult = 1;
    ASSERT_EQ(expectedResult, result);
  }

  TEST_F(QuadraticEquationTests, BasicCase2)
  {
    int result = quadraticEquation(2, -7, 3);
    int expectedResult = 3;
    ASSERT_EQ(expectedResult, result);
  }

  TEST_F(QuadraticEquationTests, BasicCase3)
  {
    int result = quadraticEquation(1,-12,-28);
    int expectedResult = 14;
    ASSERT_EQ(expectedResult, result);
  }
}
