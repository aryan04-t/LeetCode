// LeetCode (121. Best Time to Buy and Sell Stock): 
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock 


#include<vector> 
#include<algorithm> 
using namespace std;  


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(); 
        int maxProfit = 0; 

        for(int i=0; i < n-1; i++){
            for(int j=i+1; j < n; j++){
                int currProfit = prices[j] - prices[i];
                maxProfit = max(maxProfit, currProfit);     
            } 
        } 

        return maxProfit; 

    }
}; 


// T.C. = O((n * (n-1))/2) = O(n^2) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "prices" 