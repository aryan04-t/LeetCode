// LeetCode (1346. Check If N and Its Double Exist): 
// https://leetcode.com/problems/check-if-n-and-its-double-exist 


#include<vector> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:

    bool checkIfExist(vector<int>& arr) {

        int n = arr.size(); 
        unordered_multiset<int> s(arr.begin(), arr.end()); 

        for (int j=0; j < n; j++) {
            unordered_multiset<int>::iterator it = s.find(arr[j]); 
            s.erase(it); 
            if (s.find(arr[j] * 2) != s.end()) return true; 
            s.insert(arr[j]); 
        }

        return false; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = the length of 1-D input vector named "arr" 