// LeetCode (84. Largest Rectangle in Histogram): 
// https://leetcode.com/problems/largest-rectangle-in-histogram/ 


#include<vector> 
#include<stack> 
#include<limits.h> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    void findPrevSmaller(vector<int> &prevSmaller, vector<int> &heights){

        int n = heights.size();
        
        stack<int> s;
        s.push(-1);

        for(int i=0; i < n; i++){
            while(s.top() != -1 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            prevSmaller[i] = s.top();
            s.push(i);
        }

    }

    void findNextSmaller(vector<int> &nextSmaller, vector<int> &heights){

        int n = heights.size();
        
        stack<int> s;
        s.push(-1);

        for(int i=n-1; i >= 0; i--){
            while(s.top() != -1 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            nextSmaller[i] = s.top();
            s.push(i);
        }

    }

    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        vector<int> prevSmaller(n, -1);
        vector<int> nextSmaller(n, -1);

        findPrevSmaller(prevSmaller, heights);
        findNextSmaller(nextSmaller, heights);

        int maxArea = INT_MIN;

        for(int i=0; i < n; i++){
            
            if(nextSmaller[i] == -1) nextSmaller[i] = n; 

            int length = nextSmaller[i] - prevSmaller[i] - 1;
            int height = heights[i]; 

            int area  = height * length; 
            maxArea = max(area, maxArea); 

        }

        return maxArea;
    
    }
};


// T.C. = O(n) + O(n) + O(2*n-1) + O(2*n-1) + O(n) = O(n) 
// S.C. = O(n) + O(n) + O(n) + O(n) = O(n) 

// Here, n = total number of elements which are present inside the input vector named "heights" 