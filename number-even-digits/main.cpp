#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * @see https://leetcode.com/problems/find-numbers-with-even-number-of-digits/submissions/
 */
class Solution {
public:
  int findNumbers(vector<int>& nums) {
    int t_digits = 0;
    for (int i = 0; i < (int) nums.size(); ++i) {
      int digits = to_string(nums[i]).size();
      if (digits % 2 == 0) t_digits++;
    }
    return t_digits;
  }
};

template <class T>
vector<T> write_vector(vector<T> &v, int &temp, istringstream &ss) {
  while(ss >> temp) {
    v.push_back(temp);
  }
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
  int r = s.findNumbers(nums);

  cout << r << endl;

  return 0;
}