// LeetCode (3354. Make Array Elements Equal to Zero): 
// https://leetcode.com/problems/make-array-elements-equal-to-zero 


#include<vector> 
using namespace std;


class Solution {
public:

    int countValidSelections(vector<int>& nums) {

        int n = nums.size(); 
        if (n == 1) return 2; 

        int posValidSelec = 0; 

        for (int i=0; i < n; i++) {
            
            int num = nums[i]; 

            if (num == 0) {
                
                int evalLeftAndRightStart = 0;

                while (evalLeftAndRightStart < 2) {

                    vector<int> copyNums(nums.begin(), nums.end()); 

                    int j = i; 
                    bool leftDirection = (evalLeftAndRightStart == 0) ? true : false; 

                    while (j >= 0 && j < n) {
                        int currNum = copyNums[j]; 
                        if (currNum != 0) {   
                            copyNums[j]--; 
                            leftDirection = !leftDirection; 
                        }
                        if (leftDirection) j--; 
                        else j++; 
                    }

                    bool validSelection = true; 
                    for (int val : copyNums) {
                        if (val != 0) validSelection = false; 
                    }

                    if (validSelection) posValidSelec++; 
                    evalLeftAndRightStart++;
                }
            }
        }

        return posValidSelec; 
    }
};


// T.C. = O(n^2) 
// S.C. = O(n) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 