#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3642/
 */
class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> r;
    dfs(S, 0, r);
    return r;
  }
private:
  void dfs(string &S, int s, vector<string> &ans) {
    if (s == S.length()) {
      ans.push_back(S);
      return;
    }
    dfs(S, s + 1, ans);
    if (!isalpha(S[s])) return;
    S[s] ^= (1 << 5); // bit shift 32
    dfs(S, s + 1, ans);
    S[s] ^= (1 << 5);
  }
};

int main() {
  string str = "XxIozBFY67bV";
  Solution s;
  vector<string> r = s.letterCasePermutation(str);

  for (int i = 0; i < (int) r.size(); ++i)
    cout << r[i] << " ";

  cout << endl;

  return 0;
}