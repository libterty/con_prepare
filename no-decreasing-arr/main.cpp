#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
typedef long long unsigned int ll;

/**
 * @see https://leetcode.com/problems/non-decreasing-array/submissions/
 */
class Solution {
public:
  bool checkPossibility(vector<ll>& nums) {
    if (nums.size() < 2) return true;

    bool isGreater = false;
    int min_val = INT_MIN;

    for (size_t i = 0; i < nums.size() - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        if (isGreater) {
          return false;
        }

        if (nums[i+1] < min_val) {
          nums[i+1] = nums[i];
        }

        isGreater = true;
      } else {
        min_val = nums[i];
      }
    }
    return true;
  }
};

template<class T>
vector<T> write_vector(vector<T>& v, ll& temp, istringstream& ss) {
  while (ss >> temp)
    v.push_back(temp);
  return v;
}

int main() {
  string line;
  vector<ll> nums;
  ll temp;
  getline(cin, line);
  istringstream ss(line);
  nums = write_vector(nums, temp, ss);

  Solution s;
  bool result = s.checkPossibility(nums);

  cout << result << endl;

  return 0;
}