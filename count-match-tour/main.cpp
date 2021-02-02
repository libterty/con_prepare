#include <iostream>

using namespace std;

/**
 * @see https://leetcode.com/problems/count-of-matches-in-tournament/submissions/
 */
class Solution {
public:
  int numberOfMatches(int n) {
    int m = 0;
    while (n > 1) {
      m += n >> 1;
      int cnt = 0;
      if (n%2) cnt++;
      n = n >> 1;
      n += cnt;
    }
    return m;
  }
};

int main() {
  int input, r;

  cin >> input;

  Solution s;
  r = s.numberOfMatches(input);

  cout << r << endl;

  return 0;
}