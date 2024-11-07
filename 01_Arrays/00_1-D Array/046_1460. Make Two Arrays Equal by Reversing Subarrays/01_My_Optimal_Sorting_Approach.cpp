// LeetCode (1460. Make Two Arrays Equal by Reversing Subarrays): 
// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        sort(target.begin(), target.end()); 
        sort(arr.begin(), arr.end()); 

        for(int i=0; i < target.size(); i++){
            if(target[i] != arr[i]) return false; 
        }

        return true;
    }
};


// T.C. = O(n * log(n))  
// S.C. = O(log(n)) 

// Here n = the number of elements which are present inside the target array, and in this question constraints say target.size() == arr.size() 