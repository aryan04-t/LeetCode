// LeetCode (1365. How Many Numbers Are Smaller Than the Current Number): 
// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/ 
 

#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:

    int binarySearch(const int &key, const vector<int> &arr){

        int start = 0;
        int end = arr.size() - 1;
        int mid;

        while(start <= end){

            mid = start + (end - start)/2;

            if(arr[mid] == key){
                end = mid - 1;
            }
            else if(key < arr[mid]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }

        }

        return start;
    }

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> ans;
        
        for(int i=0; i < n; i++){ 
            int smallerElements = binarySearch(nums[i], sortedNums); 
            ans.push_back(smallerElements); 
        } 

        return ans;
    }
};


// T.C. = O(n) + O(n*log(n)) + O(n*log(n)) = O(n*log(n)) 
// S.C. = O(2n) = O(n) 

// Here, n = number of elements which are present inside the input vector named "nums" 
