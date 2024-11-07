// LeetCode (3075. Maximize Happiness of Selected Children): 
// https://leetcode.com/problems/maximize-happiness-of-selected-children/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        int n = happiness.size(); 
        sort(happiness.begin(), happiness.end(), greater<int>()); 

        long long totalMaxHappiness = 0; 
        int i = 0; 

        while(k-- && happiness[i] != 0){
            totalMaxHappiness += (long long)happiness[i]; 
            int j = i+1; 
            while(j < n){
                if(happiness[j] != 0) happiness[j] -= 1; 
                else break; 
                j++; 
            }
            i++; 
        }

        return totalMaxHappiness; 
    }
};


/*
    T.C. = O(n * log(n)) + O((n-1) + (n-2) + ... + (n-k)) 
         = O(n * log(n)) + O((k/2) * (2 * (n-k) + (k-1) * 1)) 
         = O(n * log(n)) + O((k/2) * (2n - 2k + k - 1)) 
         = O(n * log(n)) + O((k/2) * (2n - k - 1)) 
         = O(n * log(n)) + O((k * n) - (k^2/2) - (k/2)) 
         = O(n * log(n)) + O(k * n) 
         = max( O(n * log(n)), O(k *n) ) -> (In worst case, k == n, and O(k * n) == O(n^2)) 
*/ 

/* 
    - I used Arithmetic Progression's formula of "Sum of n terms (Sn)" to calculate the time complexity of my above written code 
    - Sn = (n/2) * (2a + (n-1) * d) -> [Here, n = k, a = n-k, d = 1] 
*/

// S.C. = O(log(n)) 

// Here, n = the total number of elements which are present inside the input vector named "happiness" 