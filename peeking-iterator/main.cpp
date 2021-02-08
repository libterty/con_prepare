#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class Iterator {
public:
  struct Data;
  Data *data;
  Iterator(const vector<int> &nums);
  Iterator(const Iterator &iter);

  // Returns the next element in the iteration.
  int next();

  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3633/
 */
class PeekingIterator : public Iterator {
private:
  int mNext;
  bool mHasNext;

public:
  PeekingIterator(const vector<int> &nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    mHasNext = Iterator::hasNext();
    if (mHasNext) {
      mNext = Iterator::next();
    }
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    return mNext;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    int t = mNext;
    mHasNext = Iterator::hasNext();
    if (mHasNext) {
      mNext = Iterator::next();
    }
    return t;
  }

  bool hasNext() const {
    return mHasNext;
  }
};

int main() { return 0; }