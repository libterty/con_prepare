#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3643/
 */
class Solution {
public:
  int maxArea(vector<int> &height) {
    int _max = 0, i = 0, size = height.size();
    while(i < size) {
      _max = max(_max, min(height[i], height[size]) * (size - i));
      if (height[i] <= height[size]) {
        i++;
      } else {
        size--;
      }
    }
    return _max;
  }
};

int main() { 
  vector<int> input { 1,8,6,2,5,4,8,3,7 };
  Solution s;
  int r = s.maxArea(input);
  cout << r << endl;
  return 0;
}