// LeetCode (2053. Kth Distinct String in an Array): 
// https://leetcode.com/problems/kth-distinct-string-in-an-array/ 


#include<vector> 
#include<string> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
       
        unordered_map<string, int> mp;
       
        for(const string &s : arr){
            mp[s]++;
        }
       
        for(const string &s : arr){
            if(mp[s] == 1) k--; 
            if(k == 0) return s;
        }

        return ""; 
    }
}; 


// T.C. = Average Case: O(n), Worst Case: O(n^2) 
// S.C. = O(n) 

// Here, n = the total number of strings which are present inside the input vector named "arr" 