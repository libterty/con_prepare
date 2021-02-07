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
  void Push_back(int x);
  void Push_cycle(ListNode *c);
  void Delete(int x);
  void Clear();
  void Reverse();
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

void LinkedList::Push_back(int x) {
  ListNode *newNode = new ListNode(x);

  if (head == 0) {
    head = newNode;
    return;
  }

  ListNode *cur = head;
  while (cur->next != 0) {
    cur = cur->next;
  }
  cur->next = newNode;
}

void LinkedList::Push_cycle(ListNode *c) {
  ListNode *cur = head;
  while (cur->next != 0) {
    cur = cur->next;
  }
  cur->next = c;
}

void LinkedList::Delete(int x) {
  ListNode *cur = head, *prev = 0;
  while (cur != 0 && cur->val != x) {
    prev = cur;
    cur = cur->next;
  }
  if (cur == head) {
    head = cur->next;
    delete cur;
    cur = 0;
  } else {
    prev->next = cur->next;
    delete cur;
    cur = 0;
  }
}

void LinkedList::Clear() {
  while(head != 0) {
    ListNode *cur = head;
    cur = cur->next;
    delete cur;
    cur = 0;
  }
}

void LinkedList::Reverse() {
  if (head == 0 && head->next == 0) return;
  ListNode *prev = 0, *cur = head, *fast = head->next;
  while(fast != 0) {
    cur->next = prev;
    prev = cur;
    cur = fast;
    fast = fast->next;
  }
  cur->next = prev;
  head = cur;
}

#endif