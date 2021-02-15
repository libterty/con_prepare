#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/problems/sequential-digits/submissions/
 */
class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> r;
    int sum ;
    for (int i = 1; i <= 9; ++i) {
      sum = 0;
      for (int j = i; j <= 9; ++j) {
        sum = sum * 10 + j;
        if (sum > high) break;
        if (sum >= low && sum <= high) {
          r.push_back(sum);
        }
      }
    }
    sort(r.begin(), r.end());
    return r;
  }
};

int main() {
  Solution s;
  vector<int> r = s.sequentialDigits(1000, 13000);

  for (size_t i = 0; i < r.size(); ++i)
    cout << r[i] << " ";
  cout << endl;
  return 0;
}