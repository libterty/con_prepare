#include <iostream>
#include <vector>
#include <queue>
#include "treenode.cpp"

using namespace std;

/**
 * @see https://leetcode.com/problems/print-binary-tree/submissions/
 */
class Solution {
public:
  vector<vector<string>> printTree(TreeNode* root) {
    return bfs(root);
  }

  vector<vector<string>> bfs(TreeNode *root) {
    int row = 0;
    int col = 0;
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
      int size = nodeQueue.size();
      while (size > 0) {
        TreeNode *node;
        node = nodeQueue.front();
        nodeQueue.pop();
        if (node -> left)
          nodeQueue.push(node -> left);
        if (node -> right)
          nodeQueue.push(node -> right);
        size--;
      }
      row++;
      col = 1 + (col << 1);
    }
    vector<vector<string>> rst(row, vector<string>(col, ""));

    recursive(rst, root, 0, 0, col - 1);

    return rst;
  }

  void recursive(vector<vector<string>>& rst, TreeNode *root, int row, int start, int end) {
    if (!root) return;

    int mid = (start + end) >> 1;

    rst[row][mid] = to_string(root -> val);

    recursive(rst, root -> left, row + 1, start, mid -1);
    recursive(rst, root -> right, row + 1, mid + 1, end);
  }
};