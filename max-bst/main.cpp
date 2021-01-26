#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "treenode.cpp"

using namespace std;

/**
 * @see https://leetcode.com/problems/maximum-binary-tree/submissions/
 */
class Solution {
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }

  TreeNode* helper(vector<int>& n, int l, int r) {
    if (l > r) return NULL;

    // find first max_element and get it's index
    vector<int>::iterator it = max_element(begin(n) + l, begin(n) + r + 1);
    int maxIndex = distance(begin(n), it);

    TreeNode* root = new TreeNode(n[maxIndex]);
    root -> left = helper(n, l, maxIndex - 1);
    root -> right = helper(n, maxIndex + 1, r);

    return root;
  }
};

template<class T>
vector<T> write_vector(vector<T>& v, int& temp, istringstream& ss) {
  while (ss >> temp)
    v.push_back(temp);
  return v;
}

int main() {
  string line;
  vector<int> nums;
  int temp;
  getline(cin, line);
  istringstream ss(line);

  nums = write_vector(nums, temp, ss);

  Solution s;
  TreeNode* r = s.constructMaximumBinaryTree(nums);

  return 0;
}