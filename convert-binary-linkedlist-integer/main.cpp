#include "linkedlist.hpp"
#include <iostream>
#include <sstream>

using namespace std;
using namespace ljh;

/**
 * @see https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/submissions/
 */
class Solution {
public:
  int getDecimalValue(ListNode *head) {
    string binaryStr;
    while(head) {
      binaryStr += to_string(head->val);
      head = head->next;
    }
    // question says binary will not more than 32 bits
    return bitset<32>(binaryStr).to_ullong();
  }
};

int main() {
  LinkedList ll;

  ll.Push_front(1);
  ll.Push_front(0);
  ll.Push_front(1);

  Solution s;
  int r = s.getDecimalValue(ll.head);
  // cout << r << endl;

  return 0;
}