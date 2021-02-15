#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/**
 * @see https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/submissions/
 */
class Solution {
public:
  vector<int> replaceElements(vector<int> &arr) {
    vector<int> r;
    for (int i = 0; i < (int) arr.size() - 1; ++i) {
      int max_el = 0;
      for (int j = i + 1; j < (int) arr.size(); ++j) {
        max_el = max(max_el, arr[j]);
      }
      r.push_back(max_el);
      max_el = 0;
    }
    r.push_back(-1);
    return r;
  }
};

int main() {
  vector<int> arr { 17, 18, 5, 4, 6, 1 };

  Solution s;
  vector<int> r = s.replaceElements(arr);
  for(int i = 0; i < (int) r.size(); ++i)
    cout << r[i] << " ";
  cout << endl;
  return 0;
}