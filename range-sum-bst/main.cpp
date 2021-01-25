#include <iostream>
#include "bst.cpp"

using namespace std;

/**
 * @see https://leetcode.com/problems/range-sum-of-bst/submissions/
 */
class Solution {
public:
  int rangeSumBST(Node* root, int low, int high) {
    if (!root) return 0;
    int sum = 0;
    if (root -> val >= low && root -> val <= high) sum = root -> val;
    return sum + rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
  }
};

int main() {
  int arr[] = { 10, 5, 15, 3, 7, 18 };
  int n = sizeof(arr)/sizeof(arr[0]);
  Node *root = insertLevelOrder(arr, root, 0, n);
  
  Solution s;
  int r = s.rangeSumBST(root, 7, 15);

  cout << r;

  return 0;
}