#include <iostream>

using namespace std;

/**
 * @see https://leetcode.com/problems/split-a-string-in-balanced-strings/submissions/
 */
class Solution {
public:
  int balancedStringSplit(string s) {
    int r = 0, br = 0, bl = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'R') {
        br++;
      } else {
        bl++;
      }
      if (br == bl) {
        br = 0;
        bl = 0;
        r++;
      }
    }
    return r;
  }
};

int main() {
  string str = "RLRRLLRLRL";

  Solution s;
  int r = s.balancedStringSplit(str);

  cout << r;

  return 0;
}