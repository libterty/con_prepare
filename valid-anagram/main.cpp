#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3636/
 */
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (t.size() != s.size()) return false;
    unordered_map<int, int> amap;
    for (const char& c : s) {
      ++amap[c];
    }
    for (const char& c : t) {
      --amap[c];
    }
    for (auto [key, value] : amap) {
      if (value != 0) return false;
    }
    
    return true;
  }
};

int main() {
  string s = "anagram", t = "nagaram";

  Solution sol;
  bool r = sol.isAnagram(s, t);
  return 0;
}