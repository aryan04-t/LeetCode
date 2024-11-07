// LeetCode (167. Two Sum II - Input Array Is Sorted): 
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        vector<int> ans{0,0};

        for(int i=0; i < n-1; i++){
            for(int j=i+1; j < n; j++){
                if(numbers[i] + numbers[j] == target){
                    ans[0] = i+1;
                    ans[1] = j+1;
                    return ans;
                }
            }
        }

        return ans; 

    }

};


// T.C. = O((n * (n-1))/2) = O(n^2) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "numbers" 