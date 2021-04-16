#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3710/
 */
class Solution {
public:
  string removeDuplicates(string s, int k) {
    vector<pair<char, int>> st{{'*', 0}};
    for (char c : s)
      if (c != st.back().first)
        st.emplace_back(c, 1);
      else if (++st.back().second == k)
        st.pop_back();
    string ans;
    for (const auto &p : st)
      ans.append(p.second, p.first);
    return ans;
  }
};

int main() {
  string s = "deeedbbcccbdaa";
  int k = 3;
  Solution sol;
  string ans = sol.removeDuplicates(s, k);
  cout << ans << endl;
  return 0;
}