#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/submissions/
 */
class Solution {
public:
  int countGoodRectangles(vector<vector<int>>& rt) {
    int cur = 0, ans = 0;
    for (auto &r : rt) {
      if (min(r[0], r[1]) > cur) {
        cur = min(r[0], r[1]);
        ans = 0;
      }
      if (min(r[0], r[1]) == cur) ++ans;
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> m
  {
    {5,8},
    {3,9},
    {5,12},
    {16,5}
  };
  Solution s;
  int r = s.countGoodRectangles(m);
  cout << r << endl;
  return 0;
}