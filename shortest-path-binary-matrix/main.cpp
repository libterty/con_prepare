#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// not goog nah
// class Solution {
// public:
//   int result;
//   int shortestPathBinaryMatrix(vector<vector<int> > &grid) {
//     for (size_t i = 0; i < grid.size(); ++i)
//       for (size_t j = 0; j < grid[i].size(); ++j)
//         dfs(grid, i, j);
//     return result;
//   }

//   void dfs(vector<vector<int> > &grid, int row, int col) {
//     int max_length = grid.size();
//     if (row < 0 || row >= max_length || col < 0 || col >= max_length) return;
//     if (grid[row][col] == 0) {
//       result++;
//       dfs(grid, row + 1, col);
//       dfs(grid, row - 1, col);
//       dfs(grid, row, col + 1);
//       dfs(grid, row, col - 1);
//     }
//   }
// };

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3638/
 */
class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int> > &grid) {
    const int m_row = grid.size(), m_col = grid[0].size();
    if (m_row == 0 || m_col == 0) return - 1;
    // 如果頭尾都是1不用看
    if (grid[0][0] == 1 || grid[m_row - 1][m_col - 1] == 1) return - 1;
    // 如果只有col只有1直接return;
    if (m_col == 1) return 1;

    queue<vector<int>> q;
    q.push({0, 0});
    int step = 1;
    while(!q.empty()) {
      for (int i = q.size(); i > 0; --i) {
        auto cur = q.front(); q.pop();
        int row = cur[0];
        int col = cur[1];
        if (row < 0 || row >= m_row || col < 0 || col >= m_col || grid[row][col] == 1) continue;
        if (row == m_row - 1 && col == m_col - 1) return step;
        
        // 標記走過
        grid[row][col] = 1;
        for (int j = -1; j <= 1; ++j) {
          for (int k = -1; k <= 1; ++k) {
            if (j == 0 && k == 0) continue;
            q.push({row + j, col + k});
          }
        }
      }
      step++;
    }
    return -1;
  }
};

int main() {
  vector<vector<int> > matrix
  {
    {0, 0, 0},
    {1, 1, 0},
    {1, 1, 0}
  };

  Solution s;
  int r = s.shortestPathBinaryMatrix(matrix);

  cout << r << endl;

  return 0;
}