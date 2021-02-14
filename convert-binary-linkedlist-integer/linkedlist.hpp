#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <iostream>

using namespace std;

namespace ljh {
  
  class LinkedList;
  
  class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {};
    ListNode(int v) : val(v), next(0) {};
    friend class LinkedList;
  };

  class LinkedList {
  public:
    ListNode *head;
    LinkedList(): head(0) {};
    
    void PrintList();
    void Push_front(int v);
    void Push_back(int v);
  };

  void LinkedList::PrintList() {
    ListNode *cur = head;
    while(cur) {
      cout << cur->val << " ";
      cur = cur->next;
    }
    cout << endl;
  }

  void LinkedList::Push_front(int v) {
    ListNode *newNode = new ListNode(v);
    newNode->next = head;
    head = newNode;
  }

  void LinkedList::Push_back(int v) {
    ListNode *newNode = new ListNode(v);
    if (head == 0) {
      head = newNode;
      return;
    }
    ListNode *temp = head;
    while (temp) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

#endif