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

        vector<bool> ans;


        for(int i=0; i < n; i++){ 

            int shouldBeMaxCandies = 0; 
            maxi = INT_MIN;
            
            shouldBeMaxCandies = candies[i] + extraCandies; 
            maxi = max(maxi, shouldBeMaxCandies); 

            for(int j=i+1, iterations = 0; iterations < n; j++, iterations++){

                if(j == n){
                    j = 0;
                }

                maxi = max(maxi, candies[j]);

                if(j == n-1){
                    j = -1;
                }

            }
            
            if(shouldBeMaxCandies == maxi){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        
        return ans;
    }
};


// T.C. = O(n^2) 
// S.C. = O(n) 

// Here, n = number of elements which are present inside the input vector named "candies" 