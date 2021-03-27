#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3686/
 */
class Solution {
public:
  int countSubstrings(string s) {
    if (s.empty()) return 0;
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
      counter(s, i, i, ans);
      counter(s, i, i + 1, ans);
    }
    return ans;
  }
private:
  void counter(string s, int i, int j, int& ans) {
    while(i >= 0 && j < s.size() && s[i] == s[j]) {
      --i;
      ++j;
      ++ans;
    }
  }
};

int main() {
  string s = "aaa";
  Solution sol;
  int ans = sol.countSubstrings(s);
  cout << ans << endl;
  return 0;
}