#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/submissions/
 */
class Solution {
public:
  vector<int> finalPrices(vector<int>& prices) {
    vector<int> ans;
    for (int i = 0; i < (int) prices.size(); ++i) {
      int discount = 0;
      for (int j = i + 1; j < (int) prices.size(); ++j) {
        if (prices[j] <= prices[i]) {
          discount = prices[j];
          break;
        }
      }
      ans.push_back(prices[i] - discount);
    }
    return ans;
  }
};

int main() {
  vector<int> prices = {10,1,1,6};
  Solution s;
  vector<int> discount = s.finalPrices(prices);
  for (int i = 0; i < (int) discount.size(); ++i)
    cout << discount[i] << " ";
  cout << endl;
  return 0;
}