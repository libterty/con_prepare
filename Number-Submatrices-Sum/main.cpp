#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3711/
 */
class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int ans = 0, m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        matrix[i][j] += matrix[i][j-1];
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        unordered_map<int, int> mp{{0,1}};
        int cur = 0;
        for (int k = 0; k < m; ++k) {
          cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1]: 0);
          ans += mp[cur - target];
          ++mp[cur];
        }
      }
    }

    return ans;
  }
};