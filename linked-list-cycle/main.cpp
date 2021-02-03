#include <iostream>
#include "linkedlist.hpp"

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3627/
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != NULL && fast->next != NULL) {
      slow = slow -> next;
      fast = fast -> next -> next;
      if (slow == fast) return true;
    }
    return false;
  }
};

int main() {
  LinkedList ll;

  ll.Push_front(-4);
  ll.Push_front(0);
  ll.Push_front(2);
  ll.Push_front(3);
  ll.Push_cycle(ll.head -> next); // same as pos 1

  Solution s;
  bool r = s.hasCycle(ll.head);

  cout << r << endl;

  return 0;
}