#include <iostream>
#include <vector>
#include "bst.cpp"

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3704/
 */
class Solution {
private:
  int ans = 0, max_depth = 0;
  void dfs(TreeNode* root, int d) {
    if (!root) return;
    if (d > max_depth) {
      max_depth = d;
      ans = 0;
    }
    if (d == max_depth) ans += root->val;
    dfs(root->left, d + 1);
    dfs(root->right, d + 1);
  }
public:
  int deepestLeavesSum(TreeNode* root) {
    dfs(root, 0);
    return ans;
  }
};

int main() {
  vector<int> arr = {1,2,3,4,5,0,6,7,0,0,0,0,8};
  int n = sizeof(arr)/sizeof(arr[0]);
  TreeNode *root = insertLevelOrder(arr, root, 0, n);
  Solution sol;
  int ans = sol.deepestLeavesSum(root);
  cout << ans << endl;
  return 0;
}