// LeetCode (Richest Customer Wealth): 
// https://leetcode.com/problems/richest-customer-wealth/ 


#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int n = accounts.size();
        int m = accounts[0].size();

        int maxi = INT_MIN;

        for(int i=0; i < n; i++){
            
            int total_money = 0;

            for(int j=0; j < m; j++){
                total_money = total_money + accounts[i][j];
            }

            maxi = max(maxi, total_money);
        }

        return maxi;
    }
};


// T.C. = O(n*m) 
// S.C. = O(1) 

// Here, n = accounts.size(), and m = accounts[0].size() 