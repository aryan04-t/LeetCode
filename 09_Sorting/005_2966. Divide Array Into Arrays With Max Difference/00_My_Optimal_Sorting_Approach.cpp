// LeetCode (2966. Divide Array Into Arrays With Max Difference): 
// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference


#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:

    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n = nums.size();

        for (int i=0; i < n - 2; i += 3) {
            int endIndex = i + 2;
            if ((nums[endIndex] - nums[i]) <= k) {
                ans.push_back({nums[i], nums[i+1], nums[i+2]});
            }
            else {
                ans = {};
                break;
            }
        }

        return ans;
    }
};


// T.C. = O(n*log(n) + O(n/3) = O(n*log(n)) 
// S.C. = O(log(n)) + O(n) = O(n) 

// Here, n = the length of nums vector 