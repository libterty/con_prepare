#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3631/
 */
class Solution {
public:
  vector<int> shortestToChar(string s, char c) {
    int n = s.size();
    vector<int> r(n, n);
    for (int i = 0; i < n; ++i) {
      if (s[i] == c) {
        r[i]  = 0;
        continue;
      }
      int j = i + 1;
      // 正向操作
      while(j < n && s[j] != c) {
        ++j;
      }
      if (j < n) r[i] = j - i;
      j = i - 1;
      // 反向操作
      while(j >= 0 && s[j] != c) {
        --j;
      }
      if (j >= 0) r[i] = min(r[i], i - j);
    }
    return r;
  }
};

int main() {
  string s = "loveleetcode";
  char c = 'e';
  Solution solution;
  vector<int> r = solution.shortestToChar(s, c);

  for (size_t i = 0; i < r.size(); ++i)
    cout << r[i] << " ";
  cout << endl;
  return 0;
}