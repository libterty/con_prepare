#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3662/
 */
class Solution {
public:
  int minimumLengthEncoding(vector<string>& words) {
    int ans = 0;
    unordered_set<string> us(words.begin(), words.end());
    for (string word : us) {
      for(int i = 1; i < word.size(); ++i) {
        us.erase(word.substr(i));
      }
    }
    for (string word : us) ans += word.size() + 1;
    return ans;
  }
};

template <class T>
vector<T> write_vector(vector<T> &v, string &temp, istringstream &ss) {
  while (ss >> temp)
    v.push_back(temp);
  return v;
}

int main() {
  string line;
  vector<string> words;
  string temp;
  getline(cin, line);
  istringstream ss(line);
  words = write_vector(words, temp, ss);
  Solution sol;
  int r = sol.minimumLengthEncoding(words);
  cout << r << endl;

  return 0;
}