#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3732/
 */
class Solution {
public:
  int jump(vector<int>& nums) {
    int res = 0, size = nums.size(), last = 0, cur = 0;
    for (int i = 0; i < size - 1; ++i) {
      cur = max(cur, i + nums[i]);
      if (i == last) {
        last = cur;
        ++res;
        if (cur >= size - 1) {
          break;
        }
      }
    }
    return res;
  }
};

int main() {
  vector<int> nums = {2,3,0,1,4};
  Solution sol;
  int ans = sol.jump(nums);
  cout << ans << endl;
  return 0;
}

