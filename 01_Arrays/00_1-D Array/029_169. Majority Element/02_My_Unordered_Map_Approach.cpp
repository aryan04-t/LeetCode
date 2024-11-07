// LeetCode (169. Majority Element): 
// https://leetcode.com/problems/majority-element/ 


#include<vector> 
#include<unordered_map> 
#include<utility> 
using namespace std; 


class Solution {
public:

    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0; i < n; i++){
            mp[nums[i]]++;
        }

        int maxi = INT_MIN; 
        int ans = nums[0];

        for(const pair<int, int> &p : mp){
            if(p.second > maxi){
                maxi = p.second;
                ans = p.first;
            }
        }

        return ans;

    }

};


// T.C. = O(n) + O(n/2) = O(3n/2) = O(n) 
// S.C. = O(n/2) = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums" 