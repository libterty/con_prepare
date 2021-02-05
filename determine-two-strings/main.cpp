#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

/**
 * @see https://leetcode.com/problems/determine-if-two-strings-are-close/submissions/
 */
class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) return false;
    unordered_map<int, int> counts1, counts2, repeat;
    for(const char& c: word1) {
      ++counts1[c];
    }
    for(const char& c: word2) {
      ++counts2[c];
    }
    for(auto [k, v]: counts1) {
      ++repeat[v];
    }
    for(auto [k, v]: counts2) {
      if (!counts1[k] || !repeat[v]--) return false;
    }
    return true;
  }
};

int main() {
  string w1 = "aaabbbbccddeeeeefffff";
  string w2 = "aaaaabbcccdddeeeeffff";

  Solution s;
  bool r = s.closeStrings(w1, w2);

  cout << r << endl;

  return 0;
}