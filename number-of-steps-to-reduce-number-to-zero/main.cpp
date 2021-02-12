#include <iostream>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3637/
 */
class Solution {
public:
  int numberOfSteps(int num) {
    int r = 0;
    while (num > 0) {
      if (num % 2 == 0) {
        num = num / 2;
      } else {
        num -= 1;
      }
      r++;
    }
    return r;
  }
};

int main() {
  int input;
  cin >> input;

  Solution s;
  int r = s.numberOfSteps(input);

  cout << r << endl;

  return 0;
}