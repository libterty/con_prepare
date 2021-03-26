#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3685/
 */
class Solution {
public:
  vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    vector<string> ans;
    vector<int> charCnt(26);
    for (string &b : B) {
      vector<int> t = helper(b);
      for (int i = 0; i < 26; ++i) {
        charCnt[i] = max(charCnt[i], t[i]);
      }
    }

    for (string &a : A) {
      vector<int> t = helper(a);
      int i = 0; 
      for (; i < 26; ++i) {
        if (t[i] < charCnt[i]) break;
      }
      if (i == 26) {
        ans.push_back(a);
      }
    }

    return ans;
  }
private:
  vector<int> helper(string& word) {
    vector<int> ans(26);
    for (char c : word) {
      ++ans[c - 'a'];
    }
    return ans;
  }
};

int main() {
  vector<string> A = {"amazon","apple","facebook","google","leetcode"};
  vector<string> B = {"ec","oc","ceo"};
  Solution sol;
  vector<string> ans = sol.wordSubsets(A, B);
  for (int i = 0; i < (int) ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}