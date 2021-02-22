#include <iostream>
#include <math.h>
using namespace std;

/**
 * @see https://leetcode.com/problems/maximum-69-number/submissions/
 */
class Solution {
public:
  int maximum69Number(int num) {
    string ans, str = to_string(num);
    int count = 0;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == '6' && count == 0) {
        count++;
        ans += '9';
      } else {
        ans += str[i];
      }
    }
    return atoi(ans.c_str());
  }
};

int main() {
  int num = 669;
  Solution s;
  int ans = s.maximum69Number(num);
  cout << ans << endl;
  return 0;
}