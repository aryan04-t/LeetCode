// LeetCode (1365. How Many Numbers Are Smaller Than the Current Number): 
// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/ 
 

#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> hashVector(101);
        vector<int> ans;

        for(int i=0; i < n; i++){
            hashVector[nums[i]]++;
        }

        for(int i=1; i < 101; i++){
            hashVector[i] = hashVector[i] + hashVector[i-1];    
        }

        for(int i=0; i < n; i++){
            if(nums[i] == 0){
                ans.push_back(0);
            }
            else{
                ans.push_back(hashVector[nums[i]-1]);
            }
        }

        return ans;
    }

};


// T.C. = O(n) + O(1) + O(n) = O(n) 
// S.C. = O(1) + O(n)  = O(n) 

// Here, n = number of elements which are present inside the input vector named "nums" 