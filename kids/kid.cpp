#include <iostream>
#include <vector>
#include <algorithm>
#include "vector.cpp"

using namespace std;
typedef long long unsigned int ll;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      ll n, i;
      n = candies.size();
      int ma = candies[0];

      for(i = 0; i < n; i++)
      {
        ma = max(ma, candies[i]);
      }

      vector<bool> answer(n, false);
      for (i = 0; i < n; i++)
      {
        if (candies[i] + extraCandies >= ma) {
          answer[i] = true;
        }
      }
      return answer;
    }
};



int main()
{
  ll t;
  Solution s;
  t = 3;
  vector<int> v = make_vector<int>() << 2 << 3 << 5 << 1 << 3;
  vector<bool> ans = s.kidsWithCandies(v, t);

  for (auto i = ans.begin(); i != ans.end(); ++i) {
    cout << *i << endl;
  }
  return 0;
}