#include <iostream>
#include <queue>

typedef long long int unsigned ll;

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3645/
 */
class Solution {
public:
  string minRemoveToMakeValid(string s) {
    queue<int> q;
    for (auto i = 0; i < s.size(); ++i) {
      if (s[i] == '(') q.push(i);
      if (s[i] == ')') {
        if (!q.empty()) {
          q.pop();
        } else {
          s[i] = '*';
        }
      }
    }
    while (!q.empty()) {
      cout << q.front() << endl;
      s[q.front()] = '*';
      q.pop();
    }
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;
  }
};

int main() {
  string input = "(a(b(c)d)";
  Solution s;
  string ans = s.minRemoveToMakeValid(input);

  cout << ans << endl;

  return 0;
}