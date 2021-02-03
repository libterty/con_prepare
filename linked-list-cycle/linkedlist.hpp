#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <iostream>

using namespace std;

class LinkedList;
class ListNode {
public:
  int val;
  ListNode *next;
  ListNode() : val(0), next(0){};
  ListNode(int v) : val(v), next(0){};
  friend class LinkedList;
};

class LinkedList {
public:
  ListNode *head;
  LinkedList() : head(0){};
  void PrintList();
  void Push_front(int x);
  void Push_cycle(ListNode *c);
};

void LinkedList::PrintList() {

  if (head == 0) {
    cout << "List is empty.\n";
    return;
  }

  ListNode *current = head;
  while (current != 0) {
    cout << current->val << " ";
    current = current->next;
  }
  cout << endl;
}

void LinkedList::Push_front(int x) {
  ListNode *newNode = new ListNode(x);
  newNode->next = head;
  head = newNode;
}

void LinkedList::Push_cycle(ListNode *c) {
  ListNode *cur = head;
  while (cur->next != 0) {
    cur = cur->next;
  }
  cur->next = c;
}

#endif