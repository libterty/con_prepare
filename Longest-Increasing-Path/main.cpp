#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3703/
 */
class Solution {
private:
  vector<vector<int>> dirs = {{0,-1}, {-1,0}, {0,1}, {1,0}};

  int dfs(vector<vector<int>>& matrix, vector<vector<int>> &dp, int i, int j) {
    if (dp[i][j]) return dp[i][j];
    int mx = 1, m = matrix.size(), n = matrix[0].size();
    for (auto dir : dirs) {
      int x = i + dir[0], y = j + dir[1];
      if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
      mx = max(mx, 1 + dfs(matrix, dp, x, y));
    }
    dp[i][j] = mx;
    return mx;
  }
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int ans = 1, y = matrix.size(), x = matrix[0].size();
    vector<vector<int>> dp(y, vector<int>(x, 0));
    for (int i = 0; i < y; ++i) {
      for (int j = 0; j < x; ++j) {
        ans = max(ans, dfs(matrix, dp, i, j));
      }
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> m = {
    {9,9,4},
    {6,6,8},
    {2,1,1},
  };
  Solution sol;
  int ans = sol.longestIncreasingPath(m);
  cout << ans << endl;
  return 0;
}