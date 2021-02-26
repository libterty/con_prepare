#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3653/
 */
class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> sk;
    int step = 0;
    for (int i = 0; i < (int) pushed.size(); ++i) {
      sk.push(pushed[i]);
      while(!sk.empty() && sk.top() == popped[step]) {
        sk.pop();
        ++step;
      }
    }
    return sk.empty();
  }
};

template<class T>
vector<T> write_vector(vector<T> &v, int &temp, istringstream &ss) {
  while(ss >> temp)
    v.push_back(temp);
  return v;
}

int main() {
  string line1, line2;
  int temp1, temp2;
  vector<int> num1, num2;
  getline(cin, line1);
  getline(cin, line2);
  istringstream ss1(line1), ss2(line2);
  num1 = write_vector(num1, temp1, ss1);
  num2 = write_vector(num2, temp2, ss2);
  Solution s;
  bool r = s.validateStackSequences(num1, num2);
  cout << r << endl;

  return 0;
}