#include <iostream>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3625/
 */
class Solution {
public:
  int hammingWeight(uint32_t n) {
    string str = bitset<32>(n).to_string();
    int t = 0;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '1')
        t++;
    }
    return t;
  }
};

int main() {
  int n = 00000000000000000000000000001011;

  Solution s;
  int t = s.hammingWeight(n);

  cout << t << endl;
  return 0;
}