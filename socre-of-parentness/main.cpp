#include <iostream>
#include <stack>

typedef long long int unsigned ll;

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3651/
 */
class Solution {
public:
  int scoreOfParentheses(string s) {
    int ans = 0;
    stack<int> st;
    for (char c : s) {
      if (c == '(') {
        st.push(ans);
        ans = 0;
      } else {
        ans = st.top() + max(ans * 2, 1);
        st.pop();
      }
    }
    return ans;
  }
};

int main() {
  string s = "(()(()))";

  Solution sol;
  int r = sol.scoreOfParentheses(s);
  cout << r << endl;

  return 0;
}