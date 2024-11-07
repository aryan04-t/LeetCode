// LeetCode (1512. Number of Good Pairs): 
// https://leetcode.com/problems/number-of-good-pairs/ 


#include<vector> 
#include<algorithm> 
using namespace std;


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int totalGoodPairs = 0;
        int count = 1;
        
        for(int i=1; i < n; i++){
            if(nums[i] == nums[i-1]) count++;
            else{
                totalGoodPairs += ((count * (count-1))/2);
                count = 1;
            }
        }

        totalGoodPairs += ((count * (count-1))/2); 

        return totalGoodPairs;

    }
};


// T.C. = O(n * log(n)) 
// S.C. = O(log(n)) 

// Here, n = total number of elements which are present inside the input vector named "nums" 