// LeetCode (169. Majority Element): 
// https://leetcode.com/problems/majority-element/ 


#include<vector> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:

    int majorityElement(vector<int>& nums) {

        int n = nums.size(); 
        unordered_map<int, int> mp; 

        for(int i=0; i < n; i++){
            mp[nums[i]]++;
        }

        n = n/2;
        int ans; 

        for(auto p : mp){
            if(p.second > n){
                ans = p.first;
                break;
            }
        }

        return ans; 

    }

};


// T.C. = O(n) + O(n/2) = O(n) 
// S.C. = O(n/2) = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums" 