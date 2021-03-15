#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3673/
 */
class Solution {
private:
  string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string base = "http://tinturl.com/";
  unordered_map<string, string> urlToKey;
  unordered_map<string, string> keyToUrl;
public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if (longUrl.empty()) return NULL;
    if (urlToKey.find(longUrl) != urlToKey.end()) return urlToKey[longUrl];
    string res = "";

    do {
      res = "";
      srand(int(time(0)));
      for (int i = 0; i < 6; i++) {
        res.push_back(dict[rand() % dict.size()]);
      }
    } while(urlToKey.find(res) != urlToKey.end());

    urlToKey[longUrl] = res;
    keyToUrl[res] = longUrl;
    return res;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    if (shortUrl.empty()) return NULL;
    string res = "";
    string temp = shortUrl.substr(shortUrl.find_last_of('/') + 1, shortUrl.size() - shortUrl.find_last_of('/') + 1);
    if (keyToUrl.find(temp) != keyToUrl.end()) {
      res = keyToUrl[temp];
    }
    return res;
  }
};

int main() {
  string lu = "https://leetcode.com/problems/design-tinyurl";
  Solution sol;
  string su = sol.encode(lu);
  cout << su << endl;
  string rlu = sol.decode(su);
  cout << rlu << endl;
  return 0;
}