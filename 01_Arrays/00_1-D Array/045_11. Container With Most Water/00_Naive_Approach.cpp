// LeetCode (11. Container With Most Water): 
// https://leetcode.com/problems/container-with-most-water/ 


// The approach gives TLE error (Obviously) 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int maxArea(vector<int>& height) {
        
        int n = height.size(); 
        int maxWater = 0; 

        for(int i=0; i < n-1; i++){
            for(int j=i+1; j < n; j++){
                int currWater = min(height[i], height[j]) * (j - i); 
                if(currWater > maxWater) maxWater = currWater; 
            }
        }

        return maxWater; 
    }
}; 


// T.C. = O((n * (n-1)) / 2) = O(n^2) 
// S.C. = O(1) 

// Here, n = the total number of integers which are present inside the input vector named "height" 