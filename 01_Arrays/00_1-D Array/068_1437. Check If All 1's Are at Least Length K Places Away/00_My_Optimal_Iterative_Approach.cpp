// LeetCode (1437. Check If All 1's Are at Least Length K Places Away): 
// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away 


#include<vector>
using namespace std;


class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int n = nums.size();
        int lastOneIndex = -1;
        bool isKPlacesAway = true;

        for (int i=0; i < n; i++) {
            int num = nums[i];

            if (num == 1) {
                if (lastOneIndex != -1) {
                    int gap = i - lastOneIndex - 1;
                    if (gap < k) {
                        isKPlacesAway = false;
                        break;
                    }
                }

                lastOneIndex = i;
            }
        }

        return isKPlacesAway;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input vector named "nums" 