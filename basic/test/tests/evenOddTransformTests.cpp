#include "testproject.h"
#include <vector>

using ::testing::ElementsAre;

/*
Create a function that performs an even-odd transform to an array, n times. Each even-odd transformation:

Adds two (+2) to each odd integer.
Subtracts two (-2) from each even integer.

evenOddTransform([3, 4, 9], 3) ➞ [9, -2, 15]
// Since [3, 4, 9] => [5, 2, 11] => [7, 0, 13] => [9, -2, 15]

evenOddTransform([0, 0, 0], 10) ➞ [-20, -20, -20]

evenOddTransform([1, 2, 3], 1) ➞ [3, 0, 5]
*/

namespace
{
  std::vector<int> evenOddTransform(std::vector<int> arr, int n) 
  {
    const auto unary = [n](const int& x)
    {
      return x + 
        ((x % 2 == 0) ? -2*n : 2*n);
    };
    
    std::transform(arr.begin(), arr.end(), arr.begin(), unary);
    return arr;
  }

  class EvenOddTransformTests :public :: testing::Test
  {

  };

  TEST_F(EvenOddTransformTests, BasicCase1)
  {
    std::vector<int> input { 3, 4, 9 };
    std::vector<int> result;
    
    result = evenOddTransform(input, 3);
    ASSERT_THAT(result, ElementsAre(9, -2, 15));
  }

  TEST_F(EvenOddTransformTests, BasicCase2)
  {
    std::vector<int> input { 0, 0, 0 };
    std::vector<int> result;
    
    result = evenOddTransform(input, 10);
    ASSERT_THAT(result, ElementsAre(-20, -20, -20));
  }

  TEST_F(EvenOddTransformTests, BasicCase3)
  {
    std::vector<int> input { 55, 90, 830 };
    std::vector<int> result;
    
    result = evenOddTransform(input, 2);
    ASSERT_THAT(result, ElementsAre(59, 86, 826));
  }
}


//It(T1){}
//	It(T2){Assert::That(evenOddTransform({0, 0, 0}, 10), Equals(std::vector<int>({-20, -20, -20})));}
//	It(T3){Assert::That(evenOddTransform({1, 2, 3}, 1), Equals(std::vector<int>({3, 0, 5})));}
//	It(T4){Assert::That(evenOddTransform({55, 90, 830}, 2), Equals(std::vector<int>({59, 86, 826})));}