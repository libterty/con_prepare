#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * @see https://leetcode.com/problems/find-the-highest-altitude/submissions/
 */
class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int start = 0, result = 0;
    for (size_t i = 0; i < gain.size(); ++i) {
      start += gain[i];
      result = max(result, start); 
    }
    return result;
  }
};

template <class T>
vector<T> write_vector(vector<T> &v, int &temp, istringstream &ss) {
  while(ss >> temp) {
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
  int r = s.largestAltitude(nums);

  cout << r << endl;

  return 0;
}