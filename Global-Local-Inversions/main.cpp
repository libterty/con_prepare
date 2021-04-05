#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3697/
 */
class Solution {
public:
  bool isIdealPermutation(vector<int>& A) {
    for (int i = 0; i < (int) A.size(); ++i) {
      if (abs(A[i] - i) > 1) return false;
    }
    return true;
  }
};

int main() {
  vector<int> v = {1,2,0};
  Solution sol;
  bool ans = sol.isIdealPermutation(v);
  cout << ans << endl;
  return 0;
}