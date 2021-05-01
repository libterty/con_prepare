#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

/**
 * @see https://leetcode.com/explore/featured/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/
 */
class WordFilter {
public:
  WordFilter(vector<string> words) {
    for (int k = 0; k < words.size(); ++k) {
      for (int i = 0; i <= words[k].size(); ++i) {
        mp[words[k].substr(0, i)].push_back(k);
      }
      for (int i = 0; i <= words[k].size(); ++i) {
        ms[words[k].substr(words[k].size() - i)].push_back(k);
      }
    }
  }

  int f(string prefix, string suffix) {
    if (!mp.count(prefix) || !ms.count(suffix))
      return -1;
    vector<int> pre = mp[prefix], suf = ms[suffix];
    int i = pre.size() - 1, j = suf.size() - 1;
    while (i >= 0 && j >= 0) {
      if (pre[i] < suf[j])
        --j;
      else if (pre[i] > suf[j])
        --i;
      else
        return pre[i];
    }
    return -1;
  }

private:
  unordered_map<string, vector<int>> mp, ms;
};

template<class T>
vector<T> write_vector(vector<T>& v, string& temp, istringstream& ss) {
  while(ss >> temp) {
    v.push_back(temp);
  }
  return v;
}

int main() {
  string line;
  vector<string> words;
  string temp;
  getline(cin, line);
  istringstream ss(line);
  words = write_vector(words, temp, ss);
  string p = "a", s = "e";
  WordFilter* obj = new WordFilter(words);
  int ans = obj->f(p, s);
  cout << ans << endl;
  return 0;
}