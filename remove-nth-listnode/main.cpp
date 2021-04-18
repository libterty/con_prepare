#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3712/
 */
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head->next) return NULL;
    ListNode* temp = head;
    ListNode* cur = head;
    for (int i = 0; i < n; ++i) {
        cur = cur->next;
    }
    if (!cur) return head->next;
    while (cur->next) {
        cur = cur->next;
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
  }
};