#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * @see https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3733/
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) return NULL;
    if (!head->next) return new TreeNode(head->val);
    ListNode *slow = head, *fast = head, *last = slow;
    while (fast->next && fast->next->next) {
      last = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    fast = slow->next;
    last->next = NULL;
    TreeNode *cur = new TreeNode(slow->val);
    if (head != slow) cur->left = sortedListToBST(head);
    cur->right = sortedListToBST(fast);
    return cur;
  }
};