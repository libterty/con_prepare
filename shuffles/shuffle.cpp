#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>


using namespace std;
typedef long long unsigned int ll;

/**
 * @See https://leetcode.com/problems/shuffle-the-array/
 */
class Solution {
public:
  vector<ll> shuffle(vector<ll>& nums, int n) {
    // result should be same size as input, n split original vector into two piece
    vector<ll> result(2 * n);
    // one start with odd, one start with even
    ll i1 = 0;
    ll i2 = 1;
    // one is increment from the begin, another increment from the target where it split, each increment jump 2
    for (ll i = 0, j = n; i < n; i++, j++) {
      result[i1] = nums[i];
      result[i2] = nums[j];
      i1 += 2;
      i2 += 2;
    }
    return result;
  }
};

template<class T>
vector<T> write_vector(vector<T>& v, ll& temp, istringstream& ss)
{
  while (ss >> temp)
    v.push_back(temp);
  return v;
}

int main()
{
  string line;
  vector<ll> nums;
  ll temp, t;
  getline(cin, line);
  cin >> t;
  istringstream ss(line);

  nums = write_vector(nums, temp, ss);

  Solution s;
  vector<ll> r = s.shuffle(nums, t);

  for (size_t i = 0; i < r.size(); i++)
    cout << r[i] << ' ';

  return 0;
}