#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {} 
};

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/592/week-5-march-29th-march-31st/3689/
 */
class Solution {
public:
  vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    vector<int> ans;
    int i = 0;
    return traverse(root, voyage, i, ans) ? ans : vector<int>{-1};
  }
private:
  bool traverse(TreeNode *n, vector<int>& v, int &i, vector<int> &ans) {
    if (!n) return true;
    if (n->val != v[i++]) return false;
    if (n->left && n->left->val != v[i]) {
      ans.push_back(n->val);
      return traverse(n->right, v, i, ans) && traverse(n->left, v, i, ans);
    }
    return traverse(n->left, v, i, ans) && traverse(n->right, v, i, ans);
  }
};