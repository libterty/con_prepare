#include <iostream>

using namespace std;

/**
 * @see https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/submissions/
 */
class Solution {
public:
  int numSteps(string s) {
    bool seen = false;
    int res = 1;
    for (int i = s.size(); i > 0; --i) {
      if (seen && s[i] == '0') {
        ++res;
      }
      if (!seen && s[i] == '1') {
        seen = true;
      }
      ++res;
    }
    if (seen) return res;
    return s.size() - 1;
  }
};

int main() {
  string s = "1111011110000011100000110001011011110010111001010111110001";
  Solution sol;
  int r = sol.numSteps(s);
  cout << r << endl;
  return 0;
}