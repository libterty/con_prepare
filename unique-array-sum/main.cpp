#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/submissions/
 */
class Solution {
public:
  vector<int> sumZero(int n) {
    int size = (n / 2);
    vector<int> v;
    for (int i = 1; i <= size; ++i) {
      v.push_back(i);
      v.push_back(-i);
    }

    if (n % 2 != 0) v.push_back(0);
    return v;
  }
};

int main() {
  Solution s;
  vector<int> r = s.sumZero(5);

  for (int i = 0; i < (int) r.size(); ++i)
    cout << r[i] << " ";

  cout << endl;
  return 0;
}