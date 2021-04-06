#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3698/
 */
class Solution {
public:
  int minOperations(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    int c = n / 2;
    int ans = 0, mid = n;
    for (int i = 0; i < c; ++i) {
      int cur = (2 * i) + 1;
      ans += (mid - cur);
    }
    return ans;
  }
};

int main() {
  int n = 3;
  Solution sol;
  int ans = sol.minOperations(3);
  cout << ans << endl;
  return 0;
}