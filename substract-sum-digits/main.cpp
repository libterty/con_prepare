#include <iostream>

using namespace std;
typedef long long unsigned int ll;

/**
 * @see https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/submissions/
 */
class Solution {
public:
  ll subtractProductAndSum(ll n) {
    string s = to_string(n);
    ll pt = 1, st = 0;
    for (ll i = 0; i < s.size(); i++) {
      int t = s[i] - '0';
      pt *= t;
      st += t;
    }
    return pt - st;
  }
};

int main() {
  ll input;
  cin >> input;

  Solution s;
  ll r = s.subtractProductAndSum(input);

  cout << r;
  return 0;
}