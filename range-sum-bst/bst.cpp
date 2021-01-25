#include <iostream>

using namespace std;

struct Node {
  int val;
  Node *left, *right;
};

Node *newNode(int val) {
  Node *node = (Node*)malloc(sizeof(Node));
  node -> val = val;
  node -> left = node -> right = NULL;
  return node;
}

Node *insertLevelOrder(int arr[], Node *root, int i, int n) {
  if (i < n) {
    Node *temp = newNode(arr[i]);
    root = temp;

    root -> left = insertLevelOrder(arr, root -> left, i * 2 + 1, n);
    root -> right = insertLevelOrder(arr, root -> right, 2 * i + 2, n);
  }
  return root;
}

void inOrder(Node *root) {
  if (root != NULL) {
    inOrder(root -> left);
    cout << root -> val << " ";
    inOrder(root -> right);
  }
}