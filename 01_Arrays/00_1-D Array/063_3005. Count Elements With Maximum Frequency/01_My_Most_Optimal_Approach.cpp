// LeetCode (3005. Count Elements With Maximum Frequency): 
// https://leetcode.com/problems/count-elements-with-maximum-frequency 


#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int maxi = INT_MIN;
        unordered_map<int, int> mp;
        
        for (int num : nums) {
            mp[num]++;
            maxi = max(maxi, mp[num]);
        }

        int sum = 0;
        for (const pair<int, int> &p : mp) {
            int currFreq = p.second;
            if (currFreq == maxi) sum += currFreq;
        }

        return sum;
    }
};


// T.C. = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = the length of input vector called "nums" 