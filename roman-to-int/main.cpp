#include <iostream>
#include <map>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3646/
 */
class Solution {
public:
  int romanToInt(string s) {
    map<char, int> mp;
    int sum = 0;
    mp.insert({ 'I', 1 });
    mp.insert({ 'V', 5 });
    mp.insert({ 'X', 10 });
    mp.insert({ 'L', 50 });
    mp.insert({ 'C', 100 });
    mp.insert({ 'D', 500 });
    mp.insert({ 'M', 1000 });
    for (int i = 0; i < s.size(); ++i) {
      if (mp[s[i]] < mp[s[i+1]]) {
        sum += mp[s[i+1]] - mp[s[i]];
        ++i;
        continue;
      }
      sum += mp[s[i]];
    }
    return sum;
  }
};

int main() {
  string input = "MCMXCIV";
  Solution s;
  int r = s.romanToInt(input);

  cout << r << endl;
  return 0;
}