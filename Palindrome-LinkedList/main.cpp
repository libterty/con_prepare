#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode *n): val(x), next(n) {}
};

/**
 * @see https://leetcode.com/explore/featured/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3693/
 */
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    vector<int> v;
    while(head) {
      v.push_back(head->val);
      head = head->next;
    }
    int n = v.size();
    for (int i = 0; i < n; ++i) {
      if (v[i] != v[n-i-1]) {
        return false;
      }
    }
    return true;
  }
};