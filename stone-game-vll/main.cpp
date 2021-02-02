#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/problems/stone-game-vii/submissions/
 */
class Solution {
public:
  int stoneGameVII(vector<int> &stones) {
    int n = stones.size();
    int diff[n][n];
    memset(diff, 0, sizeof(diff));
    int sum[n][n];
    for (int i = 0; i < n; i++)
      sum[i][i] = stones[i];

    for (int i = 2; i <= n; i++) {
      for (int j = 0; j <= n - i; j++) {
        int k = i + j - 1;
        sum[j][k] = stones[k] + sum[j][k - 1];
      }
    }

    for (int i = 2; i <= n; i++) {
      for (int j = 0; j <= n - i; j++) {
        int k = i + j - 1;
        diff[j][k] = max(sum[j + 1][k] - diff[j + 1][k], 
                         sum[j][k - 1] - diff[j][k - 1]);
      }
    }
    return diff[0][n - 1];
  }
};

template <class T>
vector<T> write_vector(vector<T> &v, int &temp, istringstream &ss) {
  while (ss >> temp)
    v.push_back(temp);
  return v;
}

int main() {
  string line;
  vector<int> nums;
  int temp;
  getline(cin, line);
  istringstream ss(line);
  nums = write_vector(nums, temp, ss);

  Solution s;
  int r = s.stoneGameVII(nums);
  cout << r << endl;

  return 0;
}