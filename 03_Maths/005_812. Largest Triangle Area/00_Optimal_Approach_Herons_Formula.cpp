// LeetCode (812. Largest Triangle Area): 
// https://leetcode.com/problems/largest-triangle-area 


// Reference YT Video: https://youtu.be/Xlkvc2IeK7M?si=3jBhvFFxIkV_Ch_H


#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


class Solution {
public:
    double calculateTriangleAreaHeronsFormula(
        vector<int> p1,
        vector<int> p2,
        vector<int> p3
    ) {
        double x1 = p1[0], y1 = p1[1];
        double x2 = p2[0], y2 = p2[1];
        double x3 = p3[0], y3 = p3[1];

        // You can also use hypot() function also instead of using pow() and sqrt() individually for side length calculation using coordinates 
        // Ex: double sideA = hypot(x2 - x1, y2 - y1); 

        double sideA = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double sideB = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        double sideC = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

        double semiParameter = (sideA + sideB + sideC)/2.0;

        double triangleArea = sqrt(semiParameter * (semiParameter - sideA) * (semiParameter - sideB) * (semiParameter - sideC)); 

        return triangleArea;
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        
        int n = points.size();
        double largestTriArea = 0.0;

        for (int i=0; i < n-2; i++) {
            for (int j=i+1; j < n-1; j++) {
                for (int k=j+1; k < n; k++) {
                  	double triangleArea = calculateTriangleAreaHeronsFormula(points[i], points[j], points[k]);
                    largestTriArea = max(largestTriArea, triangleArea);
                }
            }
        }

        return largestTriArea;
    }
};


// T.C. = O(n^3) 
// S.C. = O(1) 

// Here, n = the length of input vector named "points"  