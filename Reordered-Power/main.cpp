#include <iostream>
#include <vector>


using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3679/
 */
class Solution {
public:
  bool reorderedPowerOf2(int N) {
    vector<int> v;
    while(N) {
      v.emplace_back(N % 10);
      N /= 10;
    }
    sort(v.begin(), v.end());
    do {
      int t = 0;
      if (*v.begin() == 0) continue;
      for (const auto &a : v) {
        t *= 10;
        t += a;
      }
      if (__builtin_popcount(t) <= 1) return 1;
    } while(next_permutation(v.begin(), v.end()));
    return 0;
  }
};

int main() {
  int input = 10;
  Solution sol;
  bool ans = sol.reorderedPowerOf2(i);
  cout << ans << endl;
  return 0;
}