#include <iostream>

using namespace std;
typedef long long int unsigned ll;
typedef string str;

class Solution {
public:
  string interpret(string command) {   
    str r;
    for (str::size_type i = 0; i < command.size(); i++) {
      if (command[i] == '(' && command[i + 1] == ')') {
        r += 'o';
      } else if (command[i] != '(' && command[i] != ')') {
        r += command[i];
      }
    }
    return r;
  }
};

int main() {
  str line, t;
  cin >> line;
  Solution s;
  t = s.interpret(line);

  cout << t << endl;

  return 0;
}