#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3684/
 */
class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<vector<int>> ans;
    if (matrix.empty() || matrix[0].empty()) return ans;
    const int n = matrix.size();
    const int m = matrix[0].size();
    
    vector<vector<int>> p(n, vector<int>(m));
    vector<vector<int>> a(n, vector<int>(m));
    
    for (int x = 0; x < m; ++x) {
      dfs(matrix, x, 0, 0, p);  // top
      dfs(matrix, x, n - 1, 0, a); // bottom
    }
    
    for (int y = 0; y < n; ++y) {
      dfs(matrix, 0, y, 0, p);  // left
      dfs(matrix, m - 1, y, 0, a); // right
    }      
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (p[i][j] && a[i][j]) {
            vector<int> cell;
            cell.push_back(i);
            cell.push_back(j);
            ans.push_back(cell);
        }
                  
    return ans;
  }
private:  
  void dfs(vector<vector<int>>& b, int x, int y, int h, vector<vector<int>>& v) {
    if (x < 0 || y < 0 || x == b[0].size() || y == b.size()) return;
    if (v[y][x] || b[y][x] < h) return;
    v[y][x] = true;
    dfs(b, x + 1, y, b[y][x], v);
    dfs(b, x - 1, y, b[y][x], v);
    dfs(b, x, y + 1, b[y][x], v);
    dfs(b, x, y - 1, b[y][x], v);
  }
};

int main() {
  vector<vector<int>> m
  {
    {1,2,2,3,5},
    {3,2,3,4,4},
    {2,4,5,3,1},
    {6,7,1,4,5},
    {5,1,1,2,4}
  };
  Solution sol;
  vector<vector<int>> ans = sol.pacificAtlantic(m);
  for (int i = 0; i < (int) ans.size(); ++i) {
    for (int j = 0; j < (int) ans[i].size(); ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}