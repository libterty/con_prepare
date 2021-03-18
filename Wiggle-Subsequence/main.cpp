#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3676/
 */
class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    if (!nums.size()) return 0;
    int up = 1, down = 1;
    for (int i = 1; i < (int) nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        up = down + 1;
      }
      if (nums[i] < nums[i - 1]) {
        down = up + 1;
      }
    }
    return max(up, down);
  }
};

int main() {
  vector<int> nums = {1,7,4,9,2,5};
  Solution sol;
  int ans = sol.wiggleMaxLength(nums);
  cout << ans << endl;
  return 0;
}