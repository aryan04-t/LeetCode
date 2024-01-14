// LeetCode (1637. Widest Vertical Area Between Two Points Containing No Points): 
// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/ 


#include<vector> 
#include<set> 
#include<limits.h> 
using namespace std;


class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        set<int> xCoordinates; 
        
        for (const auto& point : points) {
            xCoordinates.insert(point[0]); 
        }
        
        int maxDiff = 0;
        int prevX = INT_MIN;
        
        for (int x : xCoordinates) {
            if (prevX != INT_MIN) {
                maxDiff = max(maxDiff, x - prevX); 
            }
            prevX = x;
        }
        
        return maxDiff;
    }
};


// T.C. = O(n * log(n)) 
// S.C. = O(n) 

// Here, n = points.size() 