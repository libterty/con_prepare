#include <iostream>
#include <vector>
#include <math.h>

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

class Solution2 {
public:
  void backtrack(vector<int> &v , int low, int high, int num) {
    int exp = log10(num), hDigit = num / pow(10, exp); // get the highest digit of each num, e.g 234 -> highest digit 2
    // 這邊看要不要進10位
    if (num % 10 < 9) {
      num = num * 10 + (num % 10) + 1;
      if (num >= low && num <= high) {
        v.push_back(num);
      }
      backtrack(v, low, high, num);
    } else {
      backtrack(v, low, high, hDigit + 1);
    }
  }

  vector<int> sequentialDigits(int low, int high) {
    vector<int> v;
    // 從1開始backtracking
    backtrack(v, low, high, 1);
    sort(v.begin(), v.end());
    return v;
  }
}

int main() {
  Solution s;
  vector<int> r = s.sequentialDigits(1000, 13000);

  for (size_t i = 0; i < r.size(); ++i)
    cout << r[i] << " ";
  cout << endl;
  return 0;
}