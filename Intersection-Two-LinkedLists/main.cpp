#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3660/
 */
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;
    while (a != b) {
      if (a) {
        a = a->next;
      } else {
        a = headB;
      }

      if (b) {
        b = b->next;
      } else {
        b = headA;
      }
    }
    return a;
  }
};