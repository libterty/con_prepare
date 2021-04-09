#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3702/
 */
class Solution {
public:
  bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> mp2;
    for (int i = 0; i < order.size(); ++i) {
      mp2[order[i]] = i;
    }

    string fs = words[0];
    for (int i = 1; i < (int) words.size(); ++i) {
      for (int j = 0; j < fs.size(); ++j) {
        if (j == words[i].size()) return false; 
        else if (mp2[fs[j]] == mp2[words[i][j]]) continue;
        else if (mp2[fs[j]] < mp2[words[i][j]]) break;
        else return false;
      }
      fs = words[i];
    }
    return true;
  }
};

int main() {
  vector<string> w = {"hello","leetcode"};
  string o = "hlabcdefgijkmnopqrstuvwxyz";
  Solution sol;
  bool ans = sol.isAlienSorted(w, o);
  cout << ans << endl;
  return 0;
}