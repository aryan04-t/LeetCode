// LeetCode (1460. Make Two Arrays Equal by Reversing Subarrays): 
// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/ 


#include<unordered_map>
#include<vector> 
using namespace std; 


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        unordered_map<int, int> mp1; 
        for(int val : target) mp1[val]++; 

        unordered_map<int, int> mp2; 
        for(int val : arr) mp2[val]++; 

        if(mp1.size() != mp2.size()) return false; 

        for(int val : target){
            if(mp1[val] != mp2[val]) return false; 
        }

        return true; 
    }
};


// T.C. -> Average Case = O(n), Worst Case = O(n^2) 
// S.C. = O(n) 

// Here n = the number of elements which are present inside the target array, and in this question constraints say target.size() == arr.size() 