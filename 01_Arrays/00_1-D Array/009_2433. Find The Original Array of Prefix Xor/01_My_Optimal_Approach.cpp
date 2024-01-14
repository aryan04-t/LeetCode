// LeetCode (2433. Find The Original Array of Prefix Xor): 
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/ 


#include<vector>
using namespace std;


class Solution {
public:
    vector<int> findArray(vector<int>& pref) {

        int n = pref.size();
        
        vector<int> ans;         
        int runningAnsArrXOR = 0; 

        
        for(int i=0; i < n; i++){

            int currAns = runningAnsArrXOR ^ pref[i]; 
            
            ans.push_back(currAns); 
        
            runningAnsArrXOR = runningAnsArrXOR ^ ans[i]; 

        }

        return ans;

    } 
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = total number of elements which are present inside the input vector named "pref" 