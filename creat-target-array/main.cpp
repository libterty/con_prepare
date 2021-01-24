#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/problems/create-target-array-in-the-given-order/submissions/
 */
class Solution {
public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> result;
    for(size_t i = 0; i < nums.size(); i++) {
      result.insert(result.begin() + index[i], nums[i]);
    }
    return result;
  }
};

int main() {
  vector<int> nums = { 0, 1, 2, 3, 4 };
  vector<int> index = { 0, 1, 2, 2, 1 };

  Solution s;
  vector<int> r = s.createTargetArray(nums, index);

  for (size_t i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }

  cout << endl;

  return 0;
}