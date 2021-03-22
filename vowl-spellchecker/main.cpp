#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3681/
 */
class Solution {
public:
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    vector<string> ans;
    unordered_set<string> us;
    unordered_map<string, string> mp1, mp2;

    for (int i = 0; i < (int) wordlist.size(); ++i) {
      string w = wordlist[i];
      us.insert(w);
      transform(w.begin(), w.end(), w.begin(), ::tolower);
      if (!mp1.count(w)) {
        mp1[w] = wordlist[i];
      }
      for (char &c : w) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
          c = '_';
        }
      }
      if (!mp2.count(w)) {
        mp2[w] = wordlist[i];
      }
    }

    for (string query : queries) {
      if (us.count(query)) {
        ans.push_back(query);
        continue;
      }

      transform(query.begin(), query.end(), query.begin(), ::tolower);

      if (mp1.count(query)) {
        ans.push_back(mp1[query]);
        continue;
      }

      for (char &c : query) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
          c = '_';
        }
      }

      if (mp2.count(query)) {
        ans.push_back(mp2[query]);
        continue;
      }
      ans.push_back("");
    }
    return ans;
  }
};

int main() {
  vector<string> wordlist = {"KiTe","kite","hare","Hare"};
  vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
  Solution sol;
  vector<string> ans = sol.spellchecker(wordlist, queries);
  for (int i = 0; i < (int) ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}