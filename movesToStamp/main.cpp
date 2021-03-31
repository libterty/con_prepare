#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/592/week-5-march-29th-march-31st/3691/
 */
class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
    vector<int> ans;
    int n = stamp.size(), t = 0;
    while (true) {
      bool isStamped = false;
      for (int size = n; size > 0; --size) {
        for (int i = 0; i <= n - size; ++i) {
          string temp = string(i, '*') + stamp.substr(i, size) + string(n - size - i, '*');
          auto p = target.find(temp);
          while(p != string::npos) {
            ans.push_back(p);
            isStamped = true;
            t += size;
            fill(begin(target) + p, begin(target) + p + n, '*');
            p = target.find(temp);
          }
        }
      }
      if (!isStamped) break;
    }
    reverse(ans.begin(), ans.end());
    return t == target.size() ? ans : vector<int>();
  }
};

int main() {
  string stamp = "abca";
  string target = "aabcaca";
  Solution sol;
  vector<int> ans = sol.movesToStamp(stamp, target);
  for (int i = 0; i < (int) ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}