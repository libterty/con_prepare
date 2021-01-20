#include <iostream>
#include <string>
#include <algorithm>


using namespace std;
typedef long long unsigned int ll;

/**
 * @see https://leetcode.com/problems/defanging-an-ip-address/
 */
class Solution {
public:
  string defangIPaddr(string s) {
    string str;
    for (int i = 0; i < s.size(); i++)
      if (s[i] == '.') 
        str += "[.]";
      else 
        str += s[i];
    return str;
  }
};


int main()
{
  string input;

  cin >> input;

  Solution s;
  string r = s.defangIPaddr(input);

  cout << r;

  return 0;
}