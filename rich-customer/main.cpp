#include <iostream>
#include <vector>


using namespace std;

int arraySum(vector<int> &v)  { 
    int initial_sum  = 0;  
    for (size_t i = 0; i < v.size(); i++)
        initial_sum += v[i];
    return initial_sum;
}

/**
 * @see https://leetcode.com/problems/richest-customer-wealth/submissions/
 */
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int total = 0;
        for (size_t i = 0; i < accounts.size(); i++) {
            int temp = arraySum(accounts[i]);
            if (total < temp) total = temp;
        }
        return total;
    }
};