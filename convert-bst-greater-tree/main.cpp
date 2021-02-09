#include "bst.cpp"
#include <iostream>
#include <queue>

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3634/
 */
class Solution {
private:
  int sum;
public:
  TreeNode *convertBST(TreeNode *root) {
    dfs(root);
    return root;
  }

  void dfs(TreeNode *node) {
    if (!node) return;
    dfs(node->right);
    sum += node -> val;
    node -> val = sum;
    dfs(node->left);
  }
};

int main() {
  int q1[] = {4, 1, 6, 0, 2, 5, 7, 0, 0, 0, 3, 0, 0, 0, 8};
  int n1 = sizeof(q1) / sizeof(q1[0]);
  TreeNode *root1 = insertLevelOrder(q1, root1, 0, n1);

  Solution s;
  TreeNode *r = s.convertBST(root1);

  inOrder(r);

  cout << endl;

  return 0;
}