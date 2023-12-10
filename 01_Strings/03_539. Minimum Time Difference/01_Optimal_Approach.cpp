// LeetCode (Minimum Time Difference): 
// https://leetcode.com/problems/minimum-time-difference/ 


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        sort(timePoints.begin(), timePoints.end());

        int n = timePoints.size();

        int hours_1, mins_1, time1;
        int hours_2, mins_2, time2;

        int mini = INT_MAX;

        for (int i = 0; i < n-1; ++i) {
          
          hours_1 = stoi( timePoints[i].substr(0, 2) );
          mins_1 = stoi( timePoints[i].substr(3, 2) );
          time1 = (60 * hours_1) + mins_1;

          hours_2 =  stoi( timePoints[i + 1].substr(0, 2) ); 
          mins_2 = stoi( timePoints[i+1].substr(3, 2) );
          time2 = (60 * hours_2) + mins_2;

          mini = min(mini, time2 - time1);
        }

        time1 = (60 * stoi( timePoints[0].substr(0, 2) ) ) + stoi( timePoints[0].substr(3, 2) );
        time2 = (60 * stoi( timePoints[n-1].substr(0, 2) ) ) + stoi( timePoints[n-1].substr(3, 2) );
        
        mini = min(mini, time1 + 1440 - time2);
        mini = min(mini, time2 - time1);

        return mini;
    }
};


// T.C.: O(m * n * log(n)) + O(n) = O(m * n * log(n)) 
// -> (t.c. of in-built sort algorithm for sorting string vector) + (traversing the whole input vector once to find the minimum time difference) 

// --> Time complexity of STL's sort function is O(n * log(n)), where n = the number of elements to be sorted. 
// --> But when this in-built sort algorithm is called to sort a string array, then the time complexity becomes O(m * n * log(n)) because of the lexicographical comparisons that has to be made, here m = the average length of the strings. 


// S.C.: O(1) -> No extra space is occupied by the above algorithm proportional to the input array size. 

// Here, n = size of input vector named "timePoints", and m = the average length of the strings. 



/*


# Which Algorithm is used by STL's sort() function: 

--> The algorithm used by STL's sort() is IntroSort. 
--> Introsort being a hybrid sorting algorithm uses three sorting algorithm to minimize the running time, Quicksort, Heapsort and Insertion Sort are the three sorting algorithms which are used by "Introsort". 



// References Cited:

* ChatGPT: https://chat.openai.com/ 
* GeeksForGeeks (Internal details of std::sort() in C++): https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/  


*/