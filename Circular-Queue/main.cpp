#include <iostream>
#include <vector>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3696/
 */
class MyCircularQueue {
private:
  vector<int> _q;
  int head = 0;
  int size = 0;

public:
  MyCircularQueue(int k) : _q(k) {}

  bool enQueue(int value) {
    if (isFull())
      return false;
    _q[(head + size) % _q.size()] = value;
    ++size;
    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;
    head = (head + 1) % _q.size();
    --size;
    return true;
  }

  int Front() { return isEmpty() ? -1 : _q[head]; }

  int Rear() { return isEmpty() ? -1 : _q[(head + size - 1) % _q.size()]; }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == _q.size(); }
};