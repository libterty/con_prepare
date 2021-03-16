#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3674/
 */
class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int sold = 0, hold = -prices[0];
    for (int i = 0; i < (int) prices.size(); ++i) {
      int temp = sold;
      sold = max(sold, hold + prices[i] - fee);
      hold = max(hold, temp - prices[i]);
    }
    return sold;
  }
};

int main() {
  vector<int> p = {1,3,2,8,4,9};
  int fee = 2;
  Solution sol;
  int ans = sol.maxProfit(p, fee);
  cout << ans << endl;
  return 0;
}