#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

TreeNode *newNode(int val) {
  TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
  node->val=val;
  node->left=node->right=NULL;
  return node;
}

TreeNode *insertNode(vector<int>& arr, TreeNode *root) {
  while(arr.size() > 0) {
    TreeNode *node = newNode(arr.front());
    arr.erase(arr.begin());
    root = node;

    root->left=insertNode(arr, root->left);
    root->right=insertNode(arr, root->right);
  }
  return root;
}

int main() {
  vector<int> nums = { 1, 3, 2, 5, 3, 9 };
  TreeNode *tree = insertNode(nums, tree);

  return 0;
}