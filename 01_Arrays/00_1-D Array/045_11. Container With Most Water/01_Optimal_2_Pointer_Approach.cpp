// LeetCode (11. Container With Most Water): 
// https://leetcode.com/problems/container-with-most-water/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int maxArea(vector<int>& height) {
        
        int n = height.size(); 

        int maxWater = 0; 
        int start = 0; 
        int end = n-1; 

        while(start < end){
            
            int currWater = min(height[start], height[end]) * (end - start); 
            if(currWater > maxWater) maxWater = currWater; 
            
            if(height[start] < height[end]) start++; 
            else if(height[start] > height[end]) end--; 
            else{
                start++; 
                end--; 
            }
        }

        return maxWater; 
    }
}; 


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of integers which are present inside the input vector named "height" 