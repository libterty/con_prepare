#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3677/
 */
class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int size = rooms.size();
    vector<int> visited(size);
    dfs(visited, rooms, 0);
    int res = 0;
    for (int v : visited) {
      res += v;
    }
    return res == size;
  }
private:
  void dfs(vector<int> &v, vector<vector<int>> &r, int p) {
    v[p] = 1;
    for (int n : r[p]) {
      if (!v[n]) {
        dfs(v, r, n);
      }
    }
  }
};

int main() {
  vector<vector<int>> rooms1
  {
    {1},
    {2},
    {3},
    {}
  };
  Solution sol;
  bool ans1 = sol.canVisitAllRooms(rooms1);
  cout << ans1 << endl;
  vector<vector<int>> rooms2
  {
    {1,3},
    {3,0,1},
    {2},
    {0}
  };
  bool ans2 = sol.canVisitAllRooms(rooms2);
  cout << ans2 << endl;
  return 0;
}