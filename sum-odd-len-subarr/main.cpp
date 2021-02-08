#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/problems/sum-of-all-odd-length-subarrays/submissions/
 */
class Solution {
public:
  int sumOddLengthSubarrays(vector<int> &arr) {
    int max_sum = 0, k = 1, n = sizeof(arr) / sizeof(arr[0]);
    return slidingWindow(arr, max_sum, n - 1, k);
  }

  int slidingWindow(vector<int> &arr, int &max_sum, int n, int k) {
    if (n < k)
      return max_sum;
    for (int i = 0; i < k; ++i) {
      max_sum += arr[i];
    }
    for (int i = k; i < n; i++) {
      max_sum += arr[i] - arr[i - k];
    }
    return slidingWindow(arr, max_sum, n, k + 2);
  }
};

class Solution2 {
public:
  int sumOddLengthSubarrays(vector<int> &arr) {
    const int n = arr.size();    
    int ans = 0;
    for (int i = 0, s = 0; i < n; ++i, s = 0)
      for (int j = i; j < n; ++j) {
        s += arr[j];
        ans += s * ((j - i + 1) & 1);
      }    
    return ans;
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
  int temp, r;
  getline(cin, line);
  istringstream ss(line);
  nums = write_vector(nums, temp, ss);

  Solution2 s;
  r = s.sumOddLengthSubarrays(nums);

  cout << r << endl;
  return 0;
}