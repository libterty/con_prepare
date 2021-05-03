#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3730/
 */
class Solution {
public:
  vector<int> runningSum(vector<int>& nums) {
    int size = nums.size();
    vector<int> ans(size);
    ans[0] = nums[0];
    for (int i = 1; i < size; ++i) {
      ans[i] = ans[i - 1] + nums[i];
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1,2,3,4};
  Solution sol;
  vector<int> ans = sol.runningSum(nums);
  for (int i = 0; i < (int) ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}