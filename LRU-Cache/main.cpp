#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

/**
 * @see https://leetcode.com/problems/lru-cache/submissions/
 */
class LRUCache {
public:
  int size;
  list<int> dll;
  unordered_map<int, pair<list<int>::iterator, int>> up;
  LRUCache(int capacity) {
    size = capacity;
  }
    
  int get(int key) {
    if (up.find(key) == up.end()) return -1;
    dll.erase(up[key].first);
    dll.push_front(key);
    up[key].first = dll.begin();
    return up[key].second;
  }
    
  void put(int key, int value) {
    if (up.find(key) != up.end()) {
      up[key].second = value;
      dll.erase(up[key].first);
      dll.push_front(key);
      up[key].first = dll.begin();
    } else {
      dll.push_front(key);
      up[key] = { dll.begin(), value };
      size--;
    }

    if (size < 0) {
      up.erase(dll.back());
      dll.pop_back();
      size++;
    }
  }
};