#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3683/
 */
class Solution {
public:
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    int n = A.size(), left = 0, right = n - 1;
    sort(A.begin(), A.end());
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; ++i) {
      pq.push({B[i], i});
    }

    vector<int> ans(n);
    while (!pq.empty()) {
      int val = pq.top().first, index = pq.top().second;
      pq.pop();
      if (A[right] > val) {
        ans[index] = A[right--];
      } else {
        ans[index] = A[left++];
      }
    }
    return ans;
  }
};


int main() {
  vector<int> A = {2,7,11,15}, B = {1,10,4,11};
  Solution sol;
  vector<int> ans = sol.advantageCount(A, B);
  for (int i = 0; i < (int) ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}