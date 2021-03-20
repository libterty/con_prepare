#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3678/
 */
class UndergroundSystem {
private:
  struct Station {
    string stationName;
    int time;
    Station(string sN, int t) : stationName(sN), time(t) {}
    Station() {}
  };

  struct RoadMap {
    double totalTime;
    double totalNumber;
    RoadMap(double tt, double tn) : totalTime(tt), totalNumber(tn) {}
    RoadMap() {}
  };

  string createKey(const string &f, const string &t) { return f + "->" + t; }

public:
  unordered_map<int, Station> checkIns;
  unordered_map<string, RoadMap> roadMaps;
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    checkIns[id] = Station(stationName, t);
  }

  void checkOut(int id, string stationName, int t) {
    Station cIn = checkIns[id];
    string k = createKey(cIn.stationName, stationName);
    int tt = t - cIn.time;

    if (roadMaps.count(k) > 0) {
      roadMaps[k].totalTime += tt;
      roadMaps[k].totalNumber++;
    } else {
      roadMaps[k] = RoadMap(tt, 1);
    }
  }

  double getAverageTime(string startStation, string endStation) {
    string k = createKey(startStation, endStation);
    RoadMap data = roadMaps[k];
    return data.totalTime / data.totalNumber;
  }
};