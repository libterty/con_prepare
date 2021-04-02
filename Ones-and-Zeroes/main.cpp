#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (string str : strs) {
      int zeros = 0, ones = 0;
      for (char c : str)
        (c == '0') ? ++zeros : ++ones;
      for (int i = m; i >= zeros; --i) {
        for (int j = n; j >= ones; --j) {
          dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
      }
    }
    return dp[m][n];
  }
};

int main() {
  vector<string> strs = {"10", "0001", "111001", "1", "0"};
  int m = 5, n = 3;
  Solution sol;
  int ans = sol.findMaxForm(strs, m, n);
  cout << ans << endl;
  return 0;
}