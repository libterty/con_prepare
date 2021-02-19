#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @see https://leetcode.com/problems/kth-missing-positive-number/submissions/
 */
class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    int l = 0;
    int r = arr.size();
    while(l < r) {
      int m = l + (r - l) / 2;
      if (arr[m] - (m + 1) >= k) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l + k;
  }
};

int main() {
  vector<int> arr = {2,3,4,7,11};
  int k = 5;
  Solution s;
  int r = s.findKthPositive(arr, k);
  cout << r << endl;
  return 0;
}