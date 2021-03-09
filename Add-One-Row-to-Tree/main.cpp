#include <iostream>
#include <stack>
#include "bst.cpp"

using namespace std;

/**
 * @see https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3666/
 */
class Solution {
public:
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 1) {
      TreeNode* temp = newNode(v);
      temp->left = root;
      root = temp;
    } else {
      stack<pair<TreeNode*, int>> st;
      st.push({ root, 2 });
      int level = 0;
      pair<TreeNode*, int> temp;
      TreeNode* node;
      while (!st.empty()) {
        /* code */
        temp = st.top();
        st.pop();
        level = temp.second;
        node = temp.first;
        if (level == d) {
          TreeNode* t1 = newNode(v);
          TreeNode* t2 = newNode(v);
          t1->left = node->left;
          t2->right = node->right;
          node->left = t1;
          node->right = t2;
        } else {
          if(node->left != NULL) {
            st.push({ node->left, level+1 });
          }
          if(node->right != NULL) {
            st.push({ node->right, level+1 });
          }
        }
      }
      
    }
    return root;
  }
};

int main() {
  int arr[] = {3,9,20,15,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  TreeNode *root = insertLevelOrder(arr, root, 0, n);

  int v = 1, d = 2;
  Solution s;
  TreeNode* r = s.addOneRow(root, v, d);
  inOrder(r);

  return 0;
}