#include <iostream>

using namespace std;

// case1: 1 + 2 * X - Y
// case2: x-y/2 + 1

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3647/
 */
class Solution {
public:
  int brokenCalc(int X, int Y) {
    int r = 0;
    while(X < Y) {
      if (Y % 2 == 0) {
        Y /= 2;
      } else {
        Y += 1;
      }
      ++r;
    }
    return r + X - Y;
  }
};

int main() {
  int x = 2, y = 3;
  Solution s;
  int r  = s.brokenCalc(x, y);
  cout << r << endl;
  return 0;
}