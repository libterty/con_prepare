#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3731/
 */
class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    int flag = 1, size = nums.size();
    for (int i = 1; i < size; ++i) {
      if (nums[i] < nums[i - 1]) {
        if (flag == 0) return false;
        if (i == 1 || nums[i] >= nums[i - 2]) {
          nums[i - 1] = nums[i];
        } else {
          nums[i] = nums[i - 1];
        }
        --flag;
      }
    }
    return true;
  }
};

int main() {
  vector<int> nums = {4,2,3};
  Solution sol;
  bool ans = sol.checkPossibility(nums);
  cout << ans << endl;
  return 0;
}