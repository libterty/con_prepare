#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3682/
 */
class Solution {
public:
  int threeSumMulti(vector<int>& arr, int target) {
    long ans = 0, M = 1e9 + 7;
    unordered_map<int, long> mp;
    for (int i = 0; i < (int) arr.size(); ++i) {
      ++mp[arr[i]];
    }

    for (auto m : mp) {
      for (auto p : mp) {
        int i = m.first, j = p.first, k = target - i - j;
        if (!mp.count(k)) continue;
        if (i == j && j == k) {
          ans += mp[i] *(mp[i] - 1) * (mp[i] - 2) / 6;
        } else if (i == j && j != k) {
          ans += mp[i] * (mp[i] - 1) / 2 * mp[k];
        } else if (i < j && j < k) {
          ans += mp[i] * mp[j] * mp[k];
        }
      }
    }
    return ans % M;
  }
};

int main() {
  vector<int> arr = {1,1,2,2,2,2};
  int t = 5;
  Solution sol;
  int ans = sol.threeSumMulti(arr, t);
  cout << ans << endl;
  return 0;
}