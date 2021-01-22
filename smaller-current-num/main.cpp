#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;
typedef string ss;

/**
 * @see https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
 */
class Solution {
public:
  vector<ll> smallerNumbersThanCurrent(vector<ll>& nums) {
    vector<ll> r;
    for (size_t i = 0; i < nums.size(); i++) {
      ll t = 0;
      for (size_t j = 0; j < nums.size(); j++) {
        if (nums[i] > nums[j]) t++;
      }
      r.push_back(t);
    }
    return r;
  }
};

template<class T>
vector<T> write_vector(vector<T>& v, ll& temp, istringstream& ss) {
  while (ss >> temp)
    v.push_back(temp);
  return v;
}

int main () {
  string line;
  vector<ll> nums, r;
  ll temp;
  getline(cin, line);
  istringstream ss(line);

  nums = write_vector(nums, temp, ss);

  Solution s;
  r = s.smallerNumbersThanCurrent(nums);

  for (size_t i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }

  cout << endl;

  return 0;
}