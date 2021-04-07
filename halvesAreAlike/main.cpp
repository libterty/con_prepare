#include <iostream>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3699/
 */
class Solution {
public:
  bool halvesAreAlike(string s) {
    string v = "aeiouAEIOU";
    int ans = 0, n = s.size() / 2;
    for (int i = 0, j = n; i < n; ++i, ++j) {
      if (~v.find(s[i])) ++ans;
      if (~v.find(s[j])) --ans;
    }
    return ans == 0;
  }
};

int main() {
  string s = "MerryChristmas";
  Solution sol;
  bool ans = sol.halvesAreAlike(s);
  cout << ans << endl;
  return 0;
}