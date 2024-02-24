// LeetCode(15. 3Sum): 
// https://leetcode.com/problems/3sum/ 


// This approach of mine gives TLE 


#include<vector> 
#include<set> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();

        set<vector<int>> s;

        for(int i=0; i < n-2; i++){
            for(int j=i+1; j < n-1; j++){
                for(int k=j+1; k < n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp{nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans;

        for(auto triplet : s){
            ans.push_back(triplet); 
        }

        return ans;

    }
};


// Sum of squares of n natural numbers = (n * (n+1) * (2n+1)) / 6 
// So, T.C. of above 3 nested loops = ((n-2) * (n-1) * (2n-3)) / 6 = O(n^3) 

// Overall T.C. = O( n^3 * ( (3 * log(3)) + log(n) ) ) + O(n) = O(n^3 * log(n)) 
// S.C. = O(n) + O(n) = O(2n) = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums" 