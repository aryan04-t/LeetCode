// LeetCode (1365. How Many Numbers Are Smaller Than the Current Number): 
// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/ 


#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> ans;
        
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                if(nums[i] == sortedNums[j]){
                    ans.push_back(j);
                    break;
                }
            }
        }

        return ans;
    }
};


// T.C. = O(n) + O(n*log(n)) + O(n^2) = O(n^2) 
// S.C. = O(2n) = O(n) 

// Here, n = number of elements which are present inside the input vector named "nums" 
