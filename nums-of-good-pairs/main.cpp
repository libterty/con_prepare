#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long int unsigned ll;

/**
 * @see https://leetcode.com/problems/number-of-good-pairs/submissions/
 */
class Solution {
public:
  ll numIdenticalPairs(vector<ll>& nums) {
    ll r = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      r += count(nums.begin() + i + 1, nums.end(), nums[i]);
    }
    return r;
  }
};

template<class T>
vector<T> write_vector(vector<T>& v, ll& temp, istringstream& ss)
{
  while (ss >> temp)
    v.push_back(temp);
  return v;
}

int main() {
  string line;
  vector<ll> nums;
  ll temp, t, r;
  getline(cin, line);
  cin >> t;
  istringstream ss(line);

  nums = write_vector(nums, temp, ss);

  Solution s;
  r = s.numIdenticalPairs(nums);

  cout << r << endl;

  return 0;
}