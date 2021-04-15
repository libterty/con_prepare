#include <iostream>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3709/
 */
class Solution {
public:
  int fib(int n) {
    if (n < 1) return 0;
    if (n <= 2) return 1;
    return fibHelper(n-1) + fibHelper(n-2);
  }
private:
  int fibHelper(int n) {
    if (n <= 1) return n;
    return fibHelper(n-1) + fibHelper(n-2);
  }
};

int main() {
  int n = 4;
  Solution sol;
  int ans = sol.fib(n);
  cout << ans << endl;
  return 0;
}