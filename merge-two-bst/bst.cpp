#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
};

TreeNode *newNode(int val) {
  TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
  node -> val = val;
  node -> left = node -> right = NULL;
  return node;
}

TreeNode *insertLevelOrder(int arr[], TreeNode *root, int i, int n) {
  if (i < n) {
    TreeNode *temp = newNode(arr[i]);
    root = temp;

    root -> left = insertLevelOrder(arr, root -> left, i * 2 + 1, n);
    root -> right = insertLevelOrder(arr, root -> right, 2 * i + 2, n);
  }
  return root;
}

void inOrder(TreeNode *root) {
  if (root != NULL) {
    inOrder(root -> left);
    cout << root -> val << " ";
    inOrder(root -> right);
  }
}