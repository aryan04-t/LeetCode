// LeetCode (786. K-th Smallest Prime Fraction): 
// https://leetcode.com/problems/k-th-smallest-prime-fraction/ 


#include<vector> 
#include<utility> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        int n = arr.size(); 

        vector<pair<double, pair<int, int>>> fractions; 

        for(int i=0; i < n; i++){
            for(int j=i+1; j < n; j++){
                double fraction = double(arr[i]) / double(arr[j]); 
                fractions.push_back({ fraction, {arr[i], arr[j]} }); 
            }
        }

        sort(fractions.begin(), fractions.end()); 

        return {fractions[k-1].second.first, fractions[k-1].second.second}; 
    }
};


/*
    T.C. = O((n * (n+1))/2) + O( ((n * (n+1))/2) * log((n * (n+1))/2) ) 
         = O(n^2) + O( n^2 * log(n^2)) 
         = O(n^2) + O( n^2 * 2 * log(n)) 
         = O(n^2 * (log(n) to the base 2)) 
*/ 

/*
    S.C. = O((n * (n+1))/2) + O(log((n * (n+1))/2)) 
         = O(n^2) + O(log(n^2) to the base 2) 
         = O(n^2) + O(2 * log(n)) 
         = O(n^2) 
*/

// Here, n = the total number of elements which are present inside the input vector name "arr" 