// LeetCode (2433. Find The Original Array of Prefix Xor): 
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/ 


#include<vector>
using namespace std;


class Solution {
public:
    vector<int> findArray(vector<int>& pref) {

        int n = pref.size();

        vector<int> ans; 
        
        
        for(int i=0; i < n; i++){

            int currAns = pref[i];
            
            for(int j=0; j < i; j++){
                currAns = currAns ^ ans[j];
            }
            
            ans.push_back(currAns);
        
        }

        return ans;

    } 
};


// T.C. = O(n^2) 
// S.C. = O(n) 

// Here, n = total number of elements which are present inside the input vector named "pref" 