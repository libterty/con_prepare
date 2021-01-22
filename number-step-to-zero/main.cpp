#include <iostream>

using namespace std;
typedef long long unsigned int ll;

/**
 * @see https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/submissions/
 */
class Solution {
public:
  ll numberOfSteps (ll num) {
    ll r = 0;
    while (num > 0) {
      if (num % 2 == 0) {
        num = num / 2;
      } else {
        num -= 1;
      }
      r++;
    }
    return r;
  }
};


int main() 
{
  ll n;
  cin >> n;

  Solution s;
  ll r = s.numberOfSteps(14);

  cout << r << endl;
  
  return 0;
}