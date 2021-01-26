#include <iostream>
#include <vector>
#include <unordered_map> 
#include "treenode.cpp"

using namespace std;
typedef long long unsigned int ll;

/**
 * @see https://leetcode.com/problems/find-duplicate-subtrees/
 */
class Solution {
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int> counts;
    vector<TreeNode*> ans;
    serialize(root, counts, ans);
    return ans;
  }
  private:
    string serialize(TreeNode* root, unordered_map<string, int>& counts, vector<TreeNode*>& ans) {
      if (!root) return "#";
      string key = to_string(root -> val) + ","
                    + serialize(root -> left, counts, ans) + ","
                    + serialize(root -> right, counts, ans);
      if (++counts[key] == 2) {
        cout << key << " ";
        ans.insert(ans.begin(), root);
      }
      return key;
    }
};

class Solution2 {
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<ll, ll> ids;
    unordered_map<ll, ll> counts;
    vector<TreeNode*> ans;
    getId(root, ids, counts, ans);
    return ans;
  }
  private:
    ll getId(TreeNode *root,
              unordered_map<ll, ll>& ids,
              unordered_map<ll, ll>& counts,
              vector<TreeNode*>& ans) {
      if (!root) return 0;
      // assuming not over 65536
      // id(root << 32, id(left) << 16, id(right))
      ll key = (static_cast<ll>(root -> val) << 32) |
               (getId(root -> left, ids, counts, ans) << 16) |
                getId(root -> right, ids, counts, ans);
      ll id;
      auto it = ids.find(key);

      if (it == ids.end())
        id = ids[key] = ids.size() + 1;
      else
        id = it -> second;

      if (++counts[id] == 2)
        ans.insert(ans.begin(), root);
      return id;
    }
};