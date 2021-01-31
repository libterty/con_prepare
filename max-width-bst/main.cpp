#include "bst.cpp"
#include <iostream>
#include <queue>

using namespace std;

/**
 * @see https://leetcode.com/problems/maximum-width-of-binary-tree/submissions/
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      if(root == NULL) return 0;
      queue <TreeNode *> unvisited;
      deque <unsigned long> visited;
    
      unvisited.push(root);
      visited.push_back(1);
      int width = 1;

      // bfs
      while(!unvisited.empty()){
        int i = unvisited.size();
        if(visited.front() - visited.back() +1 > width) {
          width = visited.front() - visited.back() + 1; 
        }
        while(i--){
          TreeNode *cur = unvisited.front();
          unvisited.pop();
          // k 代表深度，美加深一層就*2，然後右邊技術比左邊多ㄧ
          int k = (visited.front())*2;
          visited.pop_front();
          if(cur->right) {
            visited.push_back(k);
            unvisited.push(cur->right);
          }
          if(cur->left) {
            visited.push_back(k-1);
            unvisited.push(cur->left);
          }
        }
      }
      return width;        
    }
};

int main() {
  int q1[] = {1, 3, 2, 5, 3, 0, 9};
  int n1 = sizeof(q1) / sizeof(q1[0]);
  TreeNode *root1 = insertLevelOrder(q1, root1, 0, n1);

  int q2[] = { 1, 2, 3, 4, 5};
  int n2 = sizeof(q2) / sizeof(q2[0]);
  TreeNode *root2 = insertLevelOrder(q2, root2, 0, n1);

  Solution s;
  int r1 = s.widthOfBinaryTree(root1);
  cout << "Answer1:" << r1 << endl;

  int r2 = s.widthOfBinaryTree(root2);
  cout << "Answer2:" << r2 << endl;

  return 0;
}