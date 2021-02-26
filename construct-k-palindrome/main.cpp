#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * @see https://leetcode.com/problems/construct-k-palindrome-strings/submissions/
 */
class Solution {
public:
  bool canConstruct(string s, int k) {
    int size = s.size();
    if (size < k) return false;

    unordered_map<char, int> mp;
    for (const char& c : s) {
      ++mp[c];
    }

    int odd = 0;
    for (auto itr : mp) {
      if (itr.second % 2 != 0) {
        ++odd;
      }
    }

    if (odd > k) return false;

    return true;
  }
};

int main() {
  string s = "annabelle";
  int k = 2;
  Solution sol;
  bool r = sol.canConstruct(s, k);
  cout << r << endl;
  
  return 0;
}