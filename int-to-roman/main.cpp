#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3667/
 */
class Solution {
public:
  string intToRoman(int num) {
    string ans = "";
    vector<int> val {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> str {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (int i = 0; i < (int) val.size(); ++i) {
      while (num >= val[i]) {
        num -= val[i];
        ans += str[i];
      }
    }
    return ans;
  }
};

int main() {
  int num = 6;
  Solution sol;
  string ans = sol.intToRoman(num);
  cout << ans << endl;
  return 0;
}