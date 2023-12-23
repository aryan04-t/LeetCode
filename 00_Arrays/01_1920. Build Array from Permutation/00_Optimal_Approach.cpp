#include<vector>
using namespace std;


class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            ans.push_back(nums[nums[i]]);
        }

        return ans;
    }
};


// T.C. = O(n) 
// S.C. = O(n) 