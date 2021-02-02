#include <iostream>

using namespace std;

/**
 * @see https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/submissions/
 */
class Solution {
public:
  int minPartitions(string n) {
    // 只要字串裡最大的出來
    return *max_element(n.begin(), n.end()) - '0';
  }
};

int main() { 
  string input;
  cin >> input;
  Solution s;
  int r = s.minPartitions(input);
  cout << r << endl;

  return 0;
}