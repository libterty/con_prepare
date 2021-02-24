#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * @see https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/submissions/
 */
class Solution {
public:
  double average(vector<int>& s) {
    int max_s = INT_MIN, min_s = INT_MAX, sum = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
      sum += s[i];
      if (s[i] < min_s) {
        min_s = s[i];
      }
      if (s[i] > max_s) {
        max_s = s[i];
      }
    }
    return 1.0 * (sum - max_s - min_s) / ((int) s.size() - 2);
  }
};

template<class T>
vector<T> write_vector(vector<T>& v, int& temp, istringstream& ss) {
  while(ss >> temp) {
    v.push_back(temp);
  }
  return v;
}

int main() {
  string line;
  vector<int> salary;
  int temp;
  getline(cin, line);
  istringstream ss(line);
  salary = write_vector(salary, temp, ss);
  Solution s;
  double r = s.average(salary);
  cout << r << endl;

  return 0;
}