#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * @see https://leetcode.com/problems/design-underground-system/submissions/
 */
class UndergroundSystem {
private:
  
  struct CheckInStation {
    string stationName;
    int time;
    CheckInStation(string sN, int t): stationName(sN), time(t) {}
    CheckInStation() {}
  };

  struct RoadMap {
    double totalTime;
    double totalNumber;
    RoadMap(double tT, double tN): totalTime(tT), totalNumber(tN) {}
    RoadMap() {}
  };
  
  string createKey(const string &from, const string &to) {
    return from + "->" + to;
  }

public:
  unordered_map<int, CheckInStation> checkIns;
  unordered_map<string, RoadMap> roadMaps;
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    checkIns[id] = CheckInStation(stationName, t);
  }

  void checkOut(int id, string stationName, int t) {
    CheckInStation cIn = checkIns[id];
    string key = createKey(cIn.stationName, stationName);
    int tt = t - cIn.time;

    if (roadMaps.count(key) > 0) {
      roadMaps[key].totalTime += tt;
      roadMaps[key].totalNumber++;
    } else {
      roadMaps[key] = RoadMap(tt, 1);
    }
  }

  double getAverageTime(string startStation, string endStation) {
    string key = createKey(startStation, endStation);
    RoadMap data = roadMaps[key];
    return data.totalTime / data.totalNumber;
  }
};