#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3695/
 * /
class Solution {
public:
  int longestValidParentheses(string s) {
    int ans = 0, n = s.size();
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; ++i) {
      int j = i - 2 - dp[i - 1];
      if (s[i - 1] == '(' || j <0 || s[j] == ')') {
        dp[i] = 0;
      } else {
        dp[i] = dp[i - 1] + 2 + dp[j];
        ans = max(ans, dp[i]);
      }
    }

    return ans;
  }
};

int main() {
  string s = ")()())";
  Solution sol;
  int ans = sol.longestValidParentheses(s);
  cout << ans << endl;
  return 0;
}