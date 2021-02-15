#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * @see https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/submissions/
 */
class Solution {
public:
  struct Node
  {
    /* data */
    int step, x, y, k;
    Node(int s, int xx, int yy, int kk): step(s), x(xx), y(yy), k(kk) {}
  };
  

  int shortestPath(vector<vector<int>>& grid, int k) {
    queue<Node> q;
    auto n = Node(0, 0, 0, k);
    q.push(n);
    int m_row = grid.size(), m_col = grid[0].size();
    vector<vector<int>> seen(m_row, vector<int>(m_col, -1)), dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(!q.empty()) {
      auto f = q.front();
      q.pop();
      // 走到最後
      if (f.x == m_row - 1 && f.y == m_col - 1) return f.step;
      if (seen[f.x][f.y] >= f.k || f.k < 0) continue;
      seen[f.x][f.y] = f.k;
      for (auto &dir : dirs) {
        int x = f.x + dir[0];
        int y = f.y + dir[1];
        if (x >= 0 && y >= 0 && x < m_row && y < m_col && seen[x][y] < f.k - grid[x][y] && f.k - grid[x][y] >= 0) {
          q.push(Node(f.step + 1, x, y, f.k - grid[x][y]));
        }
      }
    }
    return -1;
  }
};

int main() {
  vector<vector<int> > matrix
  {
    {0,0,0},
    {1,1,0},
    {0,0,0},
    {0,1,1},
    {0,0,0}
  };
  int k = 1;

  Solution s;
  int r = s.shortestPath(matrix, k);

  cout << r;

  return 0;
}