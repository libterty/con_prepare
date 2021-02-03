#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> &cuboids) {
  for (int i = 0; i < cuboids.size(); i++) {
    for (int j = 0; j < cuboids[i].size(); j++) {
      cout << cuboids[i][j] << " ";
    }
    cout << endl;
  }
}

/**
 * @see https://leetcode.com/problems/maximum-height-by-stacking-cuboids/submissions/
 */
class Solution {
public:
  int maxHeight(vector<vector<int>> &cuboids) {
    // sort with an decrease order for cuboid height for each elements
    for (auto &cuboid : cuboids) {
      sort(cuboid.begin(), cuboid.end());
    }
    printMatrix(cuboids);
    auto compute = [](const vector<int> &a, const vector<int> &b) {
      if (a[0] == b[0] && a[1] == b[1]) {
        return a[2] > b[2];
      } else if (a[0] == b[0]) {
        return a[1] > b[1];
      } else {
        return a[0] > b[0];
      }
    };
    // sort for getting the order of the matrix
    sort(cuboids.begin(), cuboids.end(), compute);
    printMatrix(cuboids);
    int mH = 0, n = cuboids.size();

    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
      dp[i] = cuboids[i][2];
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        auto &prev = cuboids[j], &curr = cuboids[i];
        if (prev[0] >= curr[0] && prev[1] >= curr[1] && prev[2] >= curr[2]) {
          dp[i] = max(dp[i], dp[j] + curr[2]);
        }
      }
      mH = max(mH, dp[i]);
    }

    return mH;
  }
};

int main() {
  // [[50,45,20],[95,37,53],[45,23,12]]
  vector<vector<int>> cuboids{{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};

  Solution s;
  int maxHeight = s.maxHeight(cuboids);

  cout << maxHeight << endl;

  return 0;
}