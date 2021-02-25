#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3652/
 */
class Solution {
public:
  int count;
  Solution(): count(0) {}
  int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size(), i = 0, j = n - 1;
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    while(i < n && nums[i] == temp[i]) {
      ++i;
    }
    while(j > i && nums[j] == temp[j]) {
      --j;
    }
    return j - i + 1;
  }
};

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
  Solution s;
  int r = s.findUnsortedSubarray(nums);
  cout << r << endl;

  return 0;
}