#include "math.h"
#include <iostream>

using namespace std;
typedef long long int ll;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3654/
 */
class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
      return INT_MAX;
    }

    bool flag = ((dividend < 0) != (divisor < 0));
    ll dvd = abs((ll)dividend);
    ll dvs = abs((ll)divisor);

    if (dvd < dvs)
      return 0;

    ll maxShiftDigit = 0;
    while ((dvs << maxShiftDigit) <= dvd)
      ++maxShiftDigit;

    ll res = 0;
    for (ll i = maxShiftDigit - 1; i >= 0; --i) {
      unsigned int shiftValue = dvs << i;
      if (shiftValue <= dvd) {
        res += (1 << i);
        dvd -= shiftValue;
      }
    }

    return flag ? -res : res;
  }
};

int main() {
  int dd, di;
  cin >> dd;
  cin >> di;
  Solution sol;
  int r = sol.divide(dd, di);
  cout << r << endl;
  return 0;
}