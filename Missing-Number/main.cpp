#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3659/
 */
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int sum = 0, n = (int) nums.size();
    for (auto &num : nums) {
      sum += num;
    }
    return 0.5 * n * (n + 1) - sum;
  }
};

class BinarySolution {
public:
  int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int left = 0, right = (int) nums.size();
    while(left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > mid) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return right;
  }
}

template <class T>
vector<T> write_vector(vector<T> &v, int &temp, istringstream &ss) {
  while (ss >> temp)
    v.push_back(temp);
  return v;
}

int main() {
  string line;
  int temp;
  vector<int> nums;
  getline(cin, line);
  istringstream ss(line);
  nums = write_vector(nums, temp, ss);
  Solution sol;
  int r = sol.missingNumber(nums);
  cout << r << endl;
  return 0;
}