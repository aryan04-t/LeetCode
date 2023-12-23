#include<vector>
using namespace std;


class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;            // t.c. = O(1), s.c. = O(1) 

        for(int i=0, j=0; i < 2*n; i++, j++){
            ans.push_back(nums[j]);
            if(j == n-1){
                j = -1;
            }
        }

        // for loop has t.c. O(2n) 
        // and now ans vector has s.c. O(n) 

        return ans;
    }
};


// T.C. = O(2n) = O(n) 
// S.C. = O(n) 