#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3663/
 */
class MyHashMap {
private:
  vector<vector<int>> data;

public:
  /** Initialize your data structure here. */
  MyHashMap() { data.resize(1000, vector<int>()); }

  /** value will always be non-negative. */
  void put(int key, int value) {
    int hk = key % 1000;
    if (data[hk].empty()) {
      data[hk].resize(1000, -1);
    }
    data[hk][key / 1000] = value;
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) {
    int hk = key % 1000;
    if (!data[hk].empty()) {
      return data[hk][key / 1000];
    }
    return -1;
  }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) {
    int hk = key % 1000;
    if (!data[hk].empty()) {
      data[hk][key / 1000] = -1;
    }
  }
};