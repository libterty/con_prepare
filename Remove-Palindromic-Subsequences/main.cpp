#include <iostream>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3665/
 */
class Solution {
public:
  int removePalindromeSub(string s) {
    int n = s.size();
    if (n == 0) return 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
      if (s[i] != s[j]) return 2;
    }
    return 1;
  }
};

int main() {
  string input = "ababa";
  Solution sol;
  int r = sol.removePalindromeSub(input);
  cout << r << endl;
  return 0;
}