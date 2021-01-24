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

  RecentCounter* rc = new RecentCounter();
  int r1 = rc -> ping(1);
  int r2 = rc -> ping(100);
  int r3 = rc -> ping(3001);
  int r4 = rc -> ping(3002);

  cout << r1 << " " << r2 << " " << r3 << " " << r4;
  return 0;
}