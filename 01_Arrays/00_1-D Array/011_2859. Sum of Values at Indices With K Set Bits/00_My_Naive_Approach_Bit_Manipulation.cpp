// LeetCode (2859. Sum of Values at Indices With K Set Bits): 
// https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/ 


#include<vector>
using namespace std;


class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> result;

        for(int i=0; i < n; i++){
            
            int countSetBits = 0;
            int temp = i;
            
            while(temp){

                if(temp & 1){
                    countSetBits++;
                }
                
                temp = (temp >> 1); 
                
                if(countSetBits > k){
                    break;
                }
                
            }

            if(countSetBits == k){
                result.push_back(i);
            }
            
        }

        int ans = 0;
        for(auto val : result){
            ans += nums[val];
        }

        return ans;
    }
};


// T.C. = O(n * log(n)) 
// S.C. = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums" 