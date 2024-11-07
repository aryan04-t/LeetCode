// LeetCode (169. Majority Element): 
// https://leetcode.com/problems/majority-element/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int currAns = nums[0]; 
        int currCount = 1; 

        int finalAns = nums[0]; 
        int maxCount = 1; 

        int n = nums.size();

        for(int i=0; i < n-1; i++){

            if(nums[i] == nums[i+1]){
                currCount++;
            }
            else{
                maxCount = max(maxCount, currCount);
                if(maxCount == currCount){
                    finalAns = currAns;
                }
                currCount = 1;
                currAns = nums[i+1];
            }
            
        }

        maxCount = max(maxCount, currCount); 
        if(maxCount == currCount){
            finalAns = currAns;
        }

        return finalAns;

    }
};


// T.C. = O( n * log(n) ) + O(n) = O( n * log(n) ) 
// S.C. = O(log(n) to the base 2) 

// Here, n = total number of elements which are present inside the input vector named "nums" 