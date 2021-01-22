#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long unsigned int ll;
typedef string str;

class Solution {
public:
  string restoreString(string s, vector<ll>& indices) {
    vector<char> ans(s.size());
    for(int i = 0; i < s.size(); i++)
      ans[indices[i]] = s[i];    
    return string(ans.begin(), ans.end());
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
  string s = "codeleet";

  nums = write_vector(nums, temp, ss);

  Solution sol;
  string r = sol.restoreString(s, nums);

  cout << r;

  return 0;
}