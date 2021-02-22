#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3649/
 */
class Solution {
public:
  string findLongestWord(string s, vector<string> &d) {
    string r = "";
    for (int i = 0; i < (int) d.size(); ++i) {
      int j = 0;
      string str = d[i];
      for (char c : s) {
        if (j < str.size() && c == str[j]) ++j;
      }
      if (j == str.size() && str.size() >= r.size()) {
        if (str.size() > r.size() || str < r) {
          r = str;
        }
      }
    }
    return r;
  }
};

int main() {
  string s = "bab";
  vector<string> d = {"ba","ab","a","b"};
  Solution sol;

  string r = sol.findLongestWord(s, d);
  cout << r << endl;
  return 0;
}