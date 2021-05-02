#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3729/
 */
class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    int cur = 0;
    priority_queue<int> pq;
    sort(courses.begin(), courses.end(), [](vector<int>& prev, vector<int> next) {
      return prev[1] < next[1];
    });
    for (auto course : courses) {
      cur += course[0];
      pq.push(course[0]);
      if (cur > course[1]) {
        cur -= pq.top();
        pq.pop();
      }
    }
    return pq.size();
  }
};

int main() {
  vector<vector<int>> courses
  {
    {100,200},
    {200,1300},
    {1000,1250},
    {2000,3200},
  };
  Solution sol;
  int ans = sol.scheduleCourse(courses);
  cout << ans << endl;
  return 0;
}