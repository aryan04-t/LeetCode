#include<vector> 
#include<unordered_map> 
using namespace std;


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        int ans = 0;
        
        for(int i : nums){
            ans += mp[i];
            mp[i]++;
        }

        return ans;
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = number of elements present inside the input vector named "nums" 