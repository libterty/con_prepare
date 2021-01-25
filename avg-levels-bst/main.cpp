#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include "bst.cpp"

using namespace std;

/**
 * @see https://leetcode.com/problems/average-of-levels-in-binary-tree/
 */
class Solution {
public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> r;
    if (!root) return r;
    queue<TreeNode*> q;
    q.push(root);
    r.push_back(root -> val);
    while(!q.empty()) {
      root = q.front();
      q.pop();
      double s = 0;
      double n = 0;
      if (root -> left != NULL) {
        s += root -> left -> val;
        n++;
        q.push(root -> left);
      }
      if (root -> right != NULL) {
        s += root -> right -> val;
        n++;
        q.push(root -> right);
      }
      if (!isnan(s/n)) {
        r.push_back(s/n);
      }
    }
    return r;
  }
};

int main() {
  int arr[] = { 3,9,20,15,7 };
  int n = sizeof(arr)/sizeof(arr[0]);
  TreeNode *root = insertLevelOrder(arr, root, 0, n);

  Solution s;
  vector<double> r = s.averageOfLevels(root);

  for (size_t i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }

  return 0;
}