#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3650/
 */
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    if (target < matrix[0][0] || target > matrix.back().back()) return false;
    int x = matrix.size() - 1, y = 0;
    // 從右上角開始
    while(1) {
      if (matrix[x][y] > target) { // 如果大魚target往左移
        --x;
      } else if (matrix[x][y] < target) { // 如果小魚target往佑移
        ++y;
      } else {
        return true;
      }
      // 終止迴圈條件
      if (x < 0 || y >= matrix[0].size()) break;
    }
    return false;
  }
};

int main() {
  vector<vector<int>> matrix{{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};
  int target = 5;
  Solution sol;
  bool r = sol.searchMatrix(matrix, target);
  cout << r << endl;
  return 0;
}