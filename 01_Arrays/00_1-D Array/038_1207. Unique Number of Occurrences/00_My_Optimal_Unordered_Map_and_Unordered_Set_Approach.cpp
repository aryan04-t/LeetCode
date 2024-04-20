// LeetCode (1207. Unique Number of Occurrences): 
// https://leetcode.com/problems/unique-number-of-occurrences/ 


#include<vector> 
#include<unordered_map> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:

    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> mp; 
        for(int val : arr) mp[val]++; 

        unordered_set<int> s; 
        for(const pair<int, int> &p : mp){
            if(s.find(p.second) == s.end()){
                s.insert(p.second); 
            }
            else{
                return false; 
            }
        }

        return true; 
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = the total number of elements which are present inside the input vector named "arr" 