#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3675/
 */
class Solution {
private:
  const double PI = 3.14159265358979732384626433832795;
  double m_radius, m_x_center, m_y_center;
  double unifrom() {
    return (double) rand() / RAND_MAX;
  }
public:
  Solution(double radius, double x_center, double y_center) {
    srand(time(NULL));
    m_radius = radius;
    m_x_center = x_center;
    m_y_center = y_center;
  }
    
  vector<double> randPoint() {
    double temp =  2 * PI * unifrom();
    double r = sqrt(unifrom());
    return vector<double>{
      m_x_center + r * m_radius * cos(temp),
      m_y_center + r * m_radius * sin(temp)
    };
  }
};

int main() {
  Solution sol(1, 0, 0);
  vector<double> ans = sol.randPoint();
  for (int i = 0; i < (int) ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}