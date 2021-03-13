#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @see
 * https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3670/
 */
class Solution {
public:
  int numFactoredBinaryTrees(vector<int> &arr) {
    long res = 0, m = 1e9 + 7;
    unordered_map<int, long> dp;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < (int)arr.size(); ++i) {
      dp[arr[i]] = 1;
      for (int j = 0; j < i; ++j) {
        if (arr[i] % arr[j] == 0 && dp.count(arr[i] / arr[j])) {
          dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % m;
        }
      }
    }
    for (auto item : dp) {
      res = (res + item.second) % m;
    }
    return res;
  }
};

int main() {
  vector<int> arr = {18,3,6,2};
  Solution sol;
  int ans = sol.numFactoredBinaryTrees(arr);
  cout << ans << endl;
  return 0;
}