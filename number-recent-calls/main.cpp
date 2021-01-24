#include <iostream>
#include <queue>

using namespace std;

/**
 * @see https://leetcode.com/problems/number-of-recent-calls/submissions/
 */
class RecentCounter {
private:
  queue<int> q;
public:
  RecentCounter() {}

  int ping(int t) {
    q.push(t);
    while (q.front() < (t - 3000))
      q.pop();
    return q.size();
  }
};

int main() {

  RecentCounter rc;
  int r = rc.ping(3001);

  cout << r;
  return 0;
}