// LeetCode (1431. Kids With the Greatest Number of Candies): 
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/ 


#include<vector> 
#include<limits.h> 
#include<algorithm> 
using namespace std; 


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size();
        int maxi = INT_MIN;

        for(int i=0; i < n; i++){
            maxi = max(candies[i], maxi);
        }

        vector<bool> ans;
        
        for(int val : candies){
            if(val + extraCandies >= maxi) ans.push_back(true);
            else ans.push_back(false);
        }
        
        return ans;

    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = number of elements which are present inside the input vector named "candies" 



// - - - - - - - - - - 



// Optimal Approach Using max_element() STL function: 


/*

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxi = *max_element(candies.begin(), candies.end());
        
        vector<bool> ans;
        
        for(int val : candies){
            if(val + extraCandies >= maxi) ans.push_back(true);
            else ans.push_back(false);
        }
        
        return ans;

    }
};

*/


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = number of elements which are present inside the input vector named "candies" 



/*


// max_element() STL function is present in <algorithm> header file, just like max() function 

// Time Complexity of max_element() function is O(n) and Spac Complexity is O(1) 


# References Cited:

* CPlusPlus.com (std::max_element): 
https://cplusplus.com/reference/algorithm/max_element/ 



*/