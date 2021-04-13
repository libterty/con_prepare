#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3706/
 */
class NestedIterator {
private:
  stack<NestedInteger> s;

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (int i = nestedList.size() - 1; i >= 0; --i) {
      s.push(nestedList[i]);
    }
  }

  int next() {
    NestedInteger top = s.top();
    s.pop();
    return top.getInteger();
  }

  bool hasNext() {
    while (!s.empty()) {
      NestedInteger top = s.top();
      if (top.isInteger())
        return true;
      s.pop();
      for (int i = top.getList().size() - 1; i >= 0; --i) {
        s.push(top.getList()[i]);
      }
    }
    return false;
  }
};
