#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3639/
 */
class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {
    int count = 0, size = graph.size();
    vector<bool> isVisited(size, false);
    vector<int> p(size, 0);
    queue<int> q;

    q.push(0);
    p[0] = 1;
    while(!q.empty()) {
      int index = q.front();
      q.pop();
      int pS = -p[index];
      for (int item : graph[index]) {
        if (p[item] != 0 && p[item] != pS) return false;
        p[item] = pS;
        if(isVisited[item] != true) q.push(item);
      }
      if(isVisited[index] == false) count++;
      isVisited[index] = true;

      if (count != size && q.empty()) {
        for (int i = 0; i < isVisited.size(); ++i) {
          if (isVisited[i] == false) {
            q.push(i);
            p[i] = 1;
            break;
          }
        }
      }
    }
    return true;
  }
};

int main() {
  vector<vector<int>> matrix
  {
    {1,2,3},
    {0,2},
    {0,1,3},
    {0,2}
  };

  Solution s;
  bool r = s.isBipartite(matrix);

  cout << r << endl;

  return 0;
}