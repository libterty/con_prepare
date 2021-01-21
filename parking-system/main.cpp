#include <iostream>
#include <map>

using namespace std;
typedef long long int unsigned ll;

/**
 * @see https://leetcode.com/problems/design-parking-system/submissions/
 */
class ParkingSystem {
public:
  map<char, int> park;
  ParkingSystem(int big, int medium, int small) {
    park['b'] = big;
    park['m'] = medium;
    park['s'] = small;
  }
  /**
   * @param int ct car type
   */
  bool addCar(int ct) {
    if (ct == 1) {
      ParkingSystem::park['b']--;
      return ParkingSystem::park['b'] >= 0;
    } else if (ct == 2) {
      ParkingSystem::park['m']--;
      return ParkingSystem::park['m'] >= 0;
    } else {
      ParkingSystem::park['s']--;
      return ParkingSystem::park['s'] >= 0;
    }
  }
};

int main() {
  // represent big, medium, small car space
  ll b, m, s;

  cin >> b >> m >> s;

  ParkingSystem ps(1, 1, 0);

  bool p1 = ps.addCar(1);
  bool p2 = ps.addCar(2);
  bool p3 = ps.addCar(3);
  bool p4 = ps.addCar(4);

  cout << p1 << " " << p2 << " " << p3 << " " << p4;

  return 0;
}