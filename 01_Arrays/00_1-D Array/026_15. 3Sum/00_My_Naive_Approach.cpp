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
        set<vector<int>> st; 

        for(int i=0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                for(int k = j+1; k < n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp{nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans;

        for(const vector<int> &triplets : st){
            ans.push_back(triplets); 
        }

        return ans;

    }
};


// Sum of squares of n natural numbers = (n * (n+1) * (2n+1)) / 6 
// So, T.C. of above 3 nested loops = ((n-2) * (n-1) * (2n-3)) / 6 = O(n^3) 

// Overall T.C. = O( n^3 * ( (3 * log(3)) + log( (n-2) * (n-1) / 2 ) ) ) + O( (n-2) * (n-1) / 2 ) = O(n^3 * log(n^2)) + O(n^2) = O(n^3 * log(n^2)) 
// S.C. = O(n^2) + O(log(3)) + O(n^2) = O(2*(n^2)) = O(n^2) 

// Above all logs have a base of 2, and n = total number of elements which are present inside the input vector named "nums"