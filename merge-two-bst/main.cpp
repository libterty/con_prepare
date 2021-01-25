#include <iostream>
#include <queue>
#include "bst.cpp"

/**
 * @see https://leetcode.com/problems/merge-two-binary-trees/submissions/
 */
class Solution {
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return NULL;
    if (!t1) return t2;
    if (!t2) return t1;
  
    queue<TreeNode*> q1, q2;
    q1.push(t1);
    q2.push(t2);
    while(!q1.empty()) {
      TreeNode *tmp1 = q1.front(), *tmp2 = q2.front();
      q1.pop();
      q2.pop();

      tmp1 -> val += tmp2 -> val;

      if (tmp1 -> left && tmp2 -> left) {
        q1.push(tmp1 -> left);
        q2.push(tmp2 -> left);
      } else if (tmp2 -> left) {
        tmp1 -> left = tmp2 -> left;
      }

      if (tmp1 -> right && tmp2 -> right) {
        q1.push(tmp1 -> right);
        q2.push(tmp2 -> right);
      } else if (tmp2 -> right) {
        tmp1 -> right = tmp2 -> right;
      }
    }

    return t1;
  }
};

int main() {
  int arr1[] = { 1, 3, 2, 5 };
  int n1 = sizeof(arr1)/sizeof(arr1[0]);
  TreeNode *root1 = insertLevelOrder(arr1, root1, 0, n1);

  int arr2[] = { 2, 1, 3, NULL, 4, NULL, 7 };
  int n2 = sizeof(arr2)/sizeof(arr2[0]);
  TreeNode *root2 = insertLevelOrder(arr2, root2, 0, n2);

  Solution s;
  TreeNode *r = s.mergeTrees(root1, root2);

  inOrder(r);

  return 0;
}