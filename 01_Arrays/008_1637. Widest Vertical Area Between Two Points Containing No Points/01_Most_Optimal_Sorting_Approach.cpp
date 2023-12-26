// LeetCode (Widest Vertical Area Between Two Points Containing No Points): 
// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/ 


#include<vector> 
#include<limits.h> 
#include<algorithm> 
using namespace std;


class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        int maxi = INT_MIN;
        int n = points.size();

        sort(points.begin(), points.end());

        for(int i=1; i < n; i++){
            int width = points[i][0] - points[i-1][0];
            maxi = max(maxi, width);
        }

        return maxi;
    }
};


// T.C. = O(n * log(n)) 
// S.C. = O(log(n)) 

// Here, n = points.size() 

// Above both time and space complexity are O(n * log(n)) and O(log(n)) respectively due to stl's sort() function 