#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long unsigned int ll;

/**
 * @see https://leetcode.com/problems/beautiful-arrangement-ii/submissions/
 */
class Solution {
public:
  vector<int> constructArray(int n, int k) {
    vector<int> result;

    if (n == 1) {
      result.push_back(1);
      return result;
    }
    // 做配對
    int i = 1, j = k + 1;
    while (i < j) {
      // 先推頭再推尾
      result.push_back(i);
      result.push_back(j);
      i++;
      j--;
    }
    if (i == j) {
      result.push_back(i);
    }

    // 加上前兩位，如果只有兩位根本不用走進上面的回圈
    k = k + 2;
    
    while (k <= n) {
      // 不需要再有k區別，遞增增加就好
      result.push_back(k);
      k++;
    }

    return result;
  }
};

int main() {
  ll n, k;
  cin >> n;
  cin >> k;

  Solution s;
  vector<int> r = s.constructArray(n, k);

  for (size_t i = 0; i < r.size(); i++)
    cout << r[i] << " ";
  cout << endl;

  return 0;
}