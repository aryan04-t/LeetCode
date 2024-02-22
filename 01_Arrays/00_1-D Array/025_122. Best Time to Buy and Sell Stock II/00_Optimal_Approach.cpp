// LeetCode (122. Best Time to Buy and Sell Stock II): 
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/ 


#include<vector> 
#include<algorithm> 
using namespace std;


class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int maxi = prices[0];
        int mini = prices[0];

        int maxProf = 0;

        for(int i=1; i < n; i++){
            if(prices[i] > prices[i-1]){
                maxi = max(maxi, prices[i]);
            }
            else if(prices[i-1] > prices[i]){
                maxProf += (maxi - mini);
                maxi = prices[i];
                mini = prices[i];
            }
        }

        maxProf += (maxi - mini);

        return maxProf;

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector naned "prices" 