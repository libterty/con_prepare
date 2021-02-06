#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include "bst.cpp"

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3630/
 */
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> r;
    if (!root) return r;

    queue<TreeNode*> q;
    q.push(root);
    int qS = q.size();
    while(qS != 0) {
      for (int i = 1; i <= qS; ++i) {
        TreeNode* node = q.front();
        q.pop();
        if (i == qS) {
          r.push_back(node->val);
        }
        if (node->left != NULL) {
          q.push(node->left);
        }
        if (node->right != NULL) {
          q.push(node->right);
        }
      }
      qS = q.size();
    }
    return r;
  }
};

int main() {
  int arr[] = {1,2,3,0,5,0,4};
  int n = sizeof(arr)/sizeof(arr[0]);
  TreeNode *root = insertLevelOrder(arr, root, 0, n);

  Solution s;
  vector<int> r = s.rightSideView(root);

  for (size_t i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }

  return 0;
}