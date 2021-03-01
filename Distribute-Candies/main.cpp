#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * @see https://leetcode.com/explore/featured/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3657/
 */
class Solution {
public:
  int distributeCandies(vector<int>& candyType) {
    unordered_set<int> us;
    for (int i = 0; i < (int) candyType.size(); ++i) {
      us.insert(candyType[i]);
    }
    int half = (int) candyType.size() / 2;
    if (half < us.size()) return half;
    return us.size();
  }
};

int main() {
  vector<int> v = {1,1,2,3};
  Solution s;
  int r = s.distributeCandies(v);
  cout << r << endl;
  return 0;
}