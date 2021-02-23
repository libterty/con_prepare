#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * Time Limit Exceeded
 */
class Solution2 {
public:
  int minIncrementForUnique(vector<int> &A) {
    unordered_set<int> us;
    int ans = 0;
    while(A.size() > 0) {
      int cur = A.front();
      A.erase(A.begin());
      if (us.count(cur)) {
        A.push_back(cur+1);
        ++ans;
      } else {
        us.insert(cur);
      }
    }
    return ans;
  }
};

/**
 * @see https://leetcode.com/problems/minimum-increment-to-make-array-unique/submissions/
 */
class Solution {
public:
  int minIncrementForUnique(vector<int> &A) {
    int ans = 0;
    sort(A.begin(), A.end()); // 先排序好
    for (int i = 1; i < (int) A.size(); ++i) {
      if (A[i] < A[i - 1]) { // 有可能排序好後，如2222第一個輸字+1變成3222，這時候直接依照前值+1，step書現直剪前值
        int x = A[i];
        A[i] = A[i-1] + 1;
        ans += A[i] - x;
      }

      if (A[i] == A[i - 1]) {
        A[i] += 1;
        ++ans;
      }
    }
    return ans;
  }
};

template <class T>
vector<T> write_vector(vector<T> &v, int &temp, istringstream &ss) {
  while (ss >> temp) {
    v.push_back(temp);
  }
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
  int r = s.minIncrementForUnique(nums);
  cout << r << endl;
  return 0;
}