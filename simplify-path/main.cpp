#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3629/
 */
class Solution {
public:
  string simplifyPath(string path) {
    string res, temp;
    vector<string> v;
    istringstream ss(path);
    v = write_vector(v, temp, ss);
    for (string s : v) {
      res += "/" + s;
    }
    return res.empty() ? "/" : res;
  }

  vector<string> write_vector(vector<string> &v, string &temp,
                              istringstream &ss) {
    while (getline(ss, temp, '/')) {
      if (temp == "" || temp == ".")
        continue;
      if (temp == ".." && !v.empty())
        v.pop_back();
      if (temp != "..")
        v.push_back(temp);
    }
    return v;
  }
};

int main() {
  // string input = "/home/";
  string input = "/a/./b/../../c/";

  Solution s;
  string res = s.simplifyPath(input);
  cout << res << endl;

  return 0;
}