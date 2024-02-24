// LeetCode(15. 3Sum): 
// https://leetcode.com/problems/3sum/ 


#include<vector> 
#include<algorithm> 
#include<set>
using namespace std; 


class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end()); 

        set<vector<int>> s;

        for(int i=0; i < n-2; i++){
            
            int j = i+1;
            int k = n-1;

            while(j < k){

                if( (nums[i] + nums[j] + nums[k]) == 0 ){
                    s.insert({nums[i], nums[j], nums[k]}); 
                    j++;
                    k--; 
                }
                else if( (nums[i] + nums[j] + nums[k]) < 0 ){
                    j++; 
                }
                else if( (nums[i] + nums[j] + nums[k]) > 0 ){
                    k--; 
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


// T.C. = O(n * log(n)) + O( n * n * log(n) ) + O(n) = O(n^2 * log(n)) 
// S.C. = O(log(n)) + O(n) + O(n) = O(2n) = O(n) 

// Above all logs have a base of 2, and n = total number of elements which are present inside the input vector named "nums" 