// LeetCode (1460. Make Two Arrays Equal by Reversing Subarrays): 
// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/ 


#include<vector> 
#include<limits.h> 
#include<algorithm> 
using namespace std; 


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        int n = target.size(); 
        vector<int> v(1001, 0); 

        int maxi = INT_MIN; 

        for(int i=0; i < n; i++){
            int num1 = target[i]; 
            int num2 = arr[i]; 
            v[num1]++; 
            v[num2]--; 
            maxi = max(maxi, num1); 
            maxi = max(maxi, num2); 
        }

        for(int i=0; i < maxi; i++){
            if(v[i] != 0) return false;
        }

        return true; 
    }
};


// T.C. = O(n) + O(1000) = O(n) 
// S.C. = O(1000) = O(1) 

// Here n = the number of elements which are present inside the target array, and in this question constraints say target.size() == arr.size() 