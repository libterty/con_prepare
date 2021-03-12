#include <iostream>
#include <string>
#include <set>
#include <math.h>

using namespace std;

class Solution2 {
public:
  bool hasAllCodes(string s, int k) {
    for (int i = 0; i <= s.length(); ++i) {
      for (int j = 1; j <= s.length() - i; ++j) {
        string tempStr = s.substr(i, j);
        if (tempStr.size() == k) {
          string::size_type pos = s.find(tempStr);
          if (pos == s.npos) return false;
        }
      }
    }
    cout << endl;
    return true;
  }
};

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3669/
 */
class Solution {
public:
  bool hasAllCodes(string s, int k) {
    if (k > s.length()) return false;
    set<string> st;
    for (int i = 0; i + k - 1 < s.length(); ++i) {
      st.insert(s.substr(i, k));
    }
    return st.size() == pow(2, k);
  }
};

int main() {
  string s = "0110";
  int k = 2;

  Solution sol;

  bool ans = sol.hasAllCodes(s, k);
  cout << ans << endl;

  return 0;
}