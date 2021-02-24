#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/problems/the-kth-factor-of-n/submissions/
 */
class Solution {
public:
  int kthFactor(int n, int k) {
    vector<int> v;
    int size = v.size(), i = 1;
    while (size < k) {
      if (n % i == 0) {
        v.push_back(i);
      }
      if (i > n) break;
      i++;
    }
    if (v.size() == 0) return -1;
    if (v.size() < k) return -1;
    return v[k-1];
  }
};

int main() {
  int n, k;
  cin >> n;
  cin >> k;
  Solution s;
  int r = s.kthFactor(n, k);
  cout << r << endl;
  return 0;
}