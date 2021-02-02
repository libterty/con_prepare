#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};


/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3626/
 */
class Solution {
public:
  TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (!root) return NULL;
    int cur_val = root->val;
    if (cur_val < low)
      return trimBST(root->right, low, high);
    if (cur_val > high)
      return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }
};