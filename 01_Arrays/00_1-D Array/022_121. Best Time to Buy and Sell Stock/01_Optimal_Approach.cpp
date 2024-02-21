// LeetCode (121. Best Time to Buy and Sell Stock): 
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock 


#include<vector> 
#include<algorithm> 
using namespace std;  


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int minPriceTillNow = prices[0];
        int maxProf = 0;

        for(int i=1; i < n; i++){
            
            maxProf = max(maxProf, prices[i] - minPriceTillNow); 
            minPriceTillNow = min(minPriceTillNow, prices[i]); 

        }

        return maxProf;

    }
};


// T.C. = O(n)  
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "prices" 