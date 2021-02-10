#include "linkedlist.hpp"
#include <iostream>
#include <unordered_map>

using namespace std;
using namespace ljh;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3635/
 */
class Solution {
public:
  Node *copyRandomList(Node *head) {
    unordered_map<Node*, Node*> nodeMap;

    // first iterative assign map
    Node *temp = head;
    while(temp != 0) {
      nodeMap[temp] = new Node(temp->val, NULL, NULL);
      temp = temp->next;
    }

    // second iterative clear temp first
    temp = head;
    while (temp != 0) {
      nodeMap[temp]->next = nodeMap[temp->next];
      nodeMap[temp]->random = nodeMap[temp->random];
      temp = temp->next;
    }
    return nodeMap[head];
  }
};

int main() {
  LinkedList ll;

  Node n1(7, NULL, NULL);
  Node n2(13, NULL, NULL);
  Node n3(11, NULL, NULL);
  Node n4(10, NULL, NULL);
  Node n5(1, NULL, NULL);

  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  n2.random = &n1;
  n3.random = &n5;
  n4.random = &n3;
  n5.random = &n1;

  Solution s;
  Node *r = s.copyRandomList(&n1);
  ll.head = r;

  ll.PrintList();
  return 0;
}