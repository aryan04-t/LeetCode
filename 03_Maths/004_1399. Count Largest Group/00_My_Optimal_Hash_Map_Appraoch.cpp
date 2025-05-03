// LeetCode (1399. Count Largest Group): 
// https://leetcode.com/problems/count-largest-group 


class Solution {
public:
    int countLargestGroup(int n) {
        
        unordered_map<int, int> mp; 
        int maxSize = INT_MIN;

        for (int i=1; i <= n; i++) {
            int j = i; 
            int sum = 0; 
            while (j) {
                int digit = j % 10; 
                sum += digit; 
                j /= 10; 
            }
            mp[sum]++;
            if (mp[sum] > maxSize) maxSize = mp[sum]; 
        }

        int maxSizeGroupsCount = 0;

        for (const pair<int, int> &p : mp) {
            if (p.second == maxSize) maxSizeGroupsCount++;  
        }

        return maxSizeGroupsCount; 
    }
}; 


// T.C. = O(n * (log(n) to the base 10)) + O(m) = O(n * log(n)) 
// S.C. = O(m) 

// Here, n = the value of input number "n", and m = the total number of "unique digit sums" 