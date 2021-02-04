#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3628/
 */
class Solution {
public:
  int findLHS(vector<int> &nums) {
    if (nums.empty())
      return 0;
    int res = 0, start = 0, new_start = 0;
    sort(nums.begin(), nums.end());
    // sliding window idea
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] - nums[start] > 1)
        start = new_start;
      if (nums[i] != nums[i - 1])
        new_start = i;
      if (nums[i] - nums[start] == 1)
        res = max(res, i - start + 1);
    }
    return res;
  }
};

template <class T>
vector<int> write_vector(vector<T> &v, int &temp, istringstream &ss) {
  while (ss >> temp)
    v.push_back(temp);
  return v;
}

int main() {
  string line;
  vector<int> nums;
  int temp;
  getline(cin, line);
  istringstream ss(line);
  nums = write_vector(nums, temp, ss);

  Solution s;
  int r = s.findLHS(nums);

  cout << r << endl;

  return 0;
}