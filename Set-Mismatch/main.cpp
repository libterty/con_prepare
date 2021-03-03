#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3658/
 */
class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    vector<int> res(2, 0), cnt(nums.size(), 0);
    for (int num : nums)
      ++cnt[num - 1];
    for (int i = 0; i < cnt.size(); ++i) {
      if (res[0] != 0 && res[1] != 0)
        return res;
      if (cnt[i] == 2)
        res[0] = i + 1;
      else if (cnt[i] == 0)
        res[1] = i + 1;
    }
    return res;
  }
};

int main() {
  vector<int> nums = {1, 1};
  Solution s;
  vector<int> r = s.findErrorNums(nums);
  for (int i = 0; i < (int)r.size(); ++i)
    cout << r[i] << " ";
  cout << endl;
  return 0;
}