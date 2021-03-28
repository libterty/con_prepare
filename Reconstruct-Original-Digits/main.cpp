#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3687/
 */
class Solution {
public:
  string originalDigits(string s) {
    string nums[] = {"zero", "one", "two",   "three", "four",
                     "five", "six", "seven", "eight", "nine"};
    vector<int> count(10);
    string ans = "";

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'z')
        count[0]++;
      if (s[i] == 'w')
        count[2]++;
      if (s[i] == 'g')
        count[8]++;
      if (s[i] == 'x')
        count[6]++;
      if (s[i] == 'v')
        count[5]++;
      if (s[i] == 'o')
        count[1]++;
      if (s[i] == 's')
        count[7]++;
      if (s[i] == 'f')
        count[4]++;
      if (s[i] == 'h')
        count[3]++;
      if (s[i] == 'i')
        count[9]++;
    }

    count[7] -= count[6];
    count[5] -= count[7];
    count[4] -= count[5];
    count[1] -= (count[2] + count[4] + count[0]);
    count[3] -= count[8];
    count[9] -= (count[5] + count[6] + count[8]);

    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < count[i]; ++j) {
        ans += (char)(i + '0');
      }
    }

    return ans;
  }
};

int main() {
  string s = "owoztneoer";
  Solution sol;
  string ans = sol.originalDigits(s);
  cout << ans << endl;
  return 0;
}