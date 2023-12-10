// LeetCode (Minimum Time Difference): 
// https://leetcode.com/problems/minimum-time-difference/ 


// --> Sorting integers is generally faster than sorting strings because string comparison involves lexicographical comparison, while integer comparison is simpler. 

// --> That's why in this approach we will use "space-time trade-off" to improve time complexity, last algorithm which we worte had O(1) s.c., this one will have O(n) s.c. but t.c. will be reduced from O(m * n * log(n)) to O(n * log(n)) 

// --> A "space-time trade-off" is a way of solving a problem or calculation in less time by using more storage space, or by solving a problem in very little space by spending a long time.


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        int n = timePoints.size();
        vector<int> temp;

        string s;
        int hours, minutes, total;

        for(int i=0; i < n; i++){
            s = timePoints[i];
            hours = stoi(s.substr(0,2)); 
            minutes = stoi(s.substr(3,2));
            total = 60 * hours + minutes; 
            temp.push_back(total);
        }

        sort(temp.begin(), temp.end());

        int mini = INT_MAX;
        int diff;

        for(int i=0; i < n-1; i++){
            diff = temp[i+1] - temp[i];
            mini = min(mini, diff);
        }

        int last1 = (temp[0] + 1440) - temp[n-1];
        int last2 = temp[n-1] - temp[0];
        mini = min(mini, last1);
        mini = min(mini, last2);

        return mini;
    }
};


// T.C.: O(n) + O(n * log(n)) + O(n) = O(n * log(n)) 
// -> (traversing whole input vector to convert string values into minutes [integer] and storing these integer values into a new vector) + (t.c. of STL's sort function for sorting integer values) + (traversing whole vector again to find the minimum time difference) 

// S.C.: O(n) -> We're creating a integer vector of size "n", and that's why s.c. = O(n) because the size of new vector created is proportional to the size of input vector 

// Here, n = size of input vector named "timePoints" 