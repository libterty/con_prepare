#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include "bst.cpp"

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3661/
 */
class Solution {
public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ans;
    if (!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
      double sum = 0, count = 0;
      queue<TreeNode*> temp;
      while (!q.empty()) {
        TreeNode *n = q.front();
        q.pop();
        sum += n->val;
        count++;
        if (n->left != NULL)
          temp.push(n->left);
        if (n->right != NULL)
          temp.push(n->right);
      }
      q = temp;
      if (!isnan(sum/count)) ans.push_back(sum/count);
    }
    return ans;
  }
};

int main() {
  int arr[] = {3,9,20,15,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  TreeNode *root = insertLevelOrder(arr, root, 0, n);

  Solution s;
  vector<double> r = s.averageOfLevels(root);

  for (size_t i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;
  return 0;
}