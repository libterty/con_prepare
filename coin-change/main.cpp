#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3668/
 */
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < (int)coins.size(); ++j) {
        if (coins[j] <= i) {
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    return (dp[amount] > amount) ? -1 : dp[amount];
  }
};

int main() {
  int amount = 11;
  vector<int> coins = {1, 2, 5};
  Solution sol;
  int ans = sol.coinChange(coins, amount);
  cout << ans << endl;
  return 0;
}