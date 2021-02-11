#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

// languages [[2], [1,3], [1,2], [3]]
// break down
// u means user && l means languages && pointer points to user speak which languages
// {
//  u1 -> l2
//  u2 -> l1 & l3
//  u3 -> l1 & l2
//  u4 -> l3 
// }

// users [[1,4], [1,2], [3,4], [2,3]]
// create a list contains those users who canot communiacte with each others
// u1 & u4 can't share same l {1,4}
// u1 & u2 can share same l {1,4,2}
// u3 & u4 can't share same l {1,4,2,3}
// u2 & u3 can share same l1
// list {1,4,2,3}

// create a map or unordered_map to find language speak by most of user
// map;
// l2 -> 1 (u1)
// l1 -> 1 (u2) l3 -> 1 (u2)
// l1 -> 2 (u2 & u3) l2 -> 2 (u1 & u3)
// l3 -> (u2 & u4)
// { l1 -> 2 (u2 & u3) l2 -> 2 (u1 & u3) l3 -> 2 (u2 & u4) }

// extract to sets for each language who user can communicate
// { l1 -> (u2 & u3) l2 -> (u1 & u3) l3 -> (u2 & u4) }

/**
 * @see https://leetcode.com/problems/minimum-number-of-people-to-teach/submissions/
 */
class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>> &languages, 
                       vector<vector<int>> &friendships) {
    int m = languages.size(), ans = m;

    // map with sets for each language who user can communicates
    map<int, unordered_set<int>> mp;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < languages[i].size(); ++j) {
        mp[languages[i][j]].insert(i + 1);
      }
    }

    // for sets for each language who user can't communicate
    unordered_set<int> s;
    for (int i = 0; i < friendships.size(); ++i) {
      int user1 = friendships[i][0], user2 = friendships[i][1], f = 0;

      for (int j = 0; j < languages[user1 - 1].size(); ++j) {
        int l = languages[user1 - 1][j];
        if (mp[l].find(user2) != mp[l].end()) {
          f = 1;
          break;
        }
      }

      if (!f) {
        s.insert(user1);
        s.insert(user2);
      }
    }

    for (int i = 1; i <= n; ++i) {
      int c = 0;
      for (auto j : s) {
        if (mp[i].find(j) == mp[i].end()) {
          c++;
        }
      }
      ans = min(ans, c);
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> languages
  {
    {2},
    {1,3},
    {1,2},
    {3}
  };
  vector<vector<int>> friends
  {
    {1,4},
    {1,2},
    {3,4},
    {2,3}
  };

  Solution s;
  int r = s.minimumTeachings(3, languages, friends);

  cout << r << endl;

  return 0;
}