#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <iostream>

using namespace std;

namespace ljh {

  class LinkedList;
  class Node {
  public:
    int val;
    Node *next;
    Node *random;
    Node() : val(0), next(0){};
    Node(int v) : val(v), next(0){};
    Node(int v, Node* n, Node* r) {
      val = v;
      next = n;
      random = r;
    }
    friend class LinkedList;
  };

  class LinkedList {
  public:
    Node *head;
    LinkedList() : head(0){};
    void PrintList();
    void Push_front(int x);
    void Push_back(int x);
  };

  void LinkedList::PrintList() {
    if (head == 0) return;
    Node *cur = head;
    while (cur != 0) {
      cout << cur->val << " ";
      cur = cur->next;
    }
    cout << endl;
  }

  void LinkedList::Push_front(int x) {
    Node *newNode = new Node(x);
    newNode->next = head;
    head = newNode;
  }

  void LinkedList::Push_back(int x) {
    Node *newNode = new Node(x);

    if (head == 0) {
      head = newNode;
      return;
    }

    Node *cur = head;
    while (cur != 0) {
      cur = cur->next;
    }
    cur->next = newNode;
  }
} // namespace ljh

#endif