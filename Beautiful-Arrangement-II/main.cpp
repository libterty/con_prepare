#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3705/
 */
class Solution {
public:
  vector<int> constructArray(int n, int k) {
    vector<int> ans(n, 0);
    int i = 0, l = 1, r = n;
    for (; i < k; ++i) {
      if (i % 2 == 0) {
        ans[i] = l++;
      } else {
        ans[i] = r--;
      }
    }

    if (i % 2 == 1) {
      for (int j = l; j <= r; ++j) ans[i++] = j;
    } else {
      for (int j = r; j >= l; j--) ans[i++] = j;
    }

    return ans;
  }
};

int main() {
  int n = 3, k = 1;
  Solution sol;
  vector<int> ans = sol.constructArray(n,k);
  for (int i = 0; i < (int) ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}