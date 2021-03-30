#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/592/week-5-march-29th-march-31st/3690/
 */
class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& e) {
    sortMatrix(e);
    int n = e.size();
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int> dp;
    for (int i = 1; i < n; ++i) {
      int l = 0, r = dp.size(), t = e[i][1];
      while (i < r) {
        /* code */
        int mid = l + (r - l) / 2;
        if (dp[mid] < t) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      if (r >= dp.size()) {
        dp.push_back(t);
      } else {
        dp[r] = t;
      }
    }
    return dp.size();
  }
private:
  void sortMatrix(vector<vector<int>>& m) {
    sort(m.begin(), m.end(), [](vector<int> &p1, vector<int> &p2) { 
      if (p1[0] == p2[0]) return p1[1] > p2[1];
      return p1[0] < p2[0];
    });
  }
};

int main() {
  vector<vector<int>> m
  {
    {4,5},
    {4,6},
    {6,7},
    {2,3},
    {1,1},
    {1,1}
  };
  Solution sol;
  int ans = sol.maxEnvelopes(m);

  cout << ans << endl;

  return 0;
}
