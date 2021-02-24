#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * @see https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/submissions/
 */
class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int max_c = 0;
    int count = 0;
    for (int i = 0, j = 0; j < (int) nums.size(); ++j) {
      count += nums[j];
      while (i < j && count < j - i) {
        count -= nums[i++];
      }
      max_c = max(max_c, j - i);
    }
    return max_c;
  }
};

template<class T>
vector<T> write_vector(vector<T> &v, int &temp, istringstream &ss) {
  while(ss >> temp)
    v.push_back(temp);
  return v;
}

int main() {
  string line;
  int temp;
  getline(cin, line);
  istringstream ss(line);
  vector<int> nums;
  nums = write_vector(nums, temp, ss);
  Solution sol;
  int r = sol.longestSubarray(nums);
  cout << r << endl;
  return 0;
}