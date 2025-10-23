// LeetCode (3718. Smallest Missing Multiple of K) 
// https://leetcode.com/problems/smallest-missing-multiple-of-k 


#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;
        for (int val : nums) st.insert(val);

        bool ansFound = false;
        int temp = 1;
        int missingNum = k;
        
        while (!ansFound) {
            missingNum = k * temp;
            if (st.find(missingNum) == st.end()) {
                ansFound = true;
                break;
            }
            temp++;
        }

        return missingNum;
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = the length of input vector named "nums" 