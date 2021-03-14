#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3671/
 */
class Solution {
public:
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode *temp1 = head, *temp2 = head, *kth = nullptr;
    while(--k) {
      temp1 = temp1->next;
    }
    kth = temp1;
    temp1 = temp1->next;

    while (temp1) {
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    swap(temp2->val, kth->val);
    return head;
  }
};