// LeetCode (3354. Make Array Elements Equal to Zero): 
// https://leetcode.com/problems/make-array-elements-equal-to-zero 


#include<vector> 
using namespace std;


class Solution {
public:

    int countValidSelections(vector<int>& nums) {

        int n = nums.size(); 
        if (n == 1) return 2; 

        vector<int> left(n, 0); 
        vector<int> right(n, 0); 

        int posValidSelec = 0; 

        int i = 0; 
        while (i < n) { 
            if (i == 0) left[i] = nums[i]; 
            else left[i] = left[i-1] + nums[i]; 
            i++; 
        } 

        i = n-1; 
        while (i >= 0) {
            if (i == n-1) right[i] = nums[i]; 
            else right[i] = right[i+1] + nums[i]; 
            i--; 
        }

        for (int i=0; i < n; i++) {
            
            int num = nums[i]; 
            
            if (num == 0) {
               
                int leftSum = (i > 0) ? left[i-1] : 0; 
                int rightSum = (i < n-1) ? right[i+1] : 0; 
               
                if (leftSum == rightSum) {
                    posValidSelec += 2; 
                }
                else if ((leftSum == rightSum+1) || (leftSum+1 == rightSum)) {
                    posValidSelec += 1; 
                }
            }
        }

        return posValidSelec; 
    }
};


// T.C. = O(2n) + O(2n) + O(n) = Initializing 2 vectors + processing nums 2 times for left and right prefix sum + one last pass to calculate all the valid possible selections = O(5n) = O(n) 
// S.C. = O(2n) = O(n) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 