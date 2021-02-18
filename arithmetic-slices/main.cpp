#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3644/
 */
class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int res = 0, len = 2, size = A.size();

    for (int i = 2; i < size; ++i) {
      // 是等差
      if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
        ++len;
      } else {
        if (len > 2) res += (len - 1) * (len - 2) * 0.5;
        len = 2;
      }
    }

    if (len > 2) res += (len - 1) * (len - 2) * 0.5;
    return res;
  }
};

class SolutionDp {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int r, size = A.size();
    vector<int> dp(size, 0);
    for (int i = 2; i < size; ++i) {
      if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
        dp[i] = dp[i - 1] + 1;
      }
      r += dp[i];
    }
    return r;
  }
};


int main() {
  vector<int> v = {1,2,3,4};
  SolutionDp s;
  int r = s.numberOfArithmeticSlices(v);
  cout << r << endl;
  return 0;
}