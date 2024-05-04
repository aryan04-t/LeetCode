// LeetCode (881. Boats to Save People): 
// https://leetcode.com/problems/boats-to-save-people/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end()); 

        int n = people.size(); 
        int i = 0, j = n-1; 
        int boats = 0;

        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
            }
            j--;
            boats++;
        }

        return boats; 
    }
};


// T.C. = O(n * log(n)) + O(n) = O(n * log(n)) 
// S.C. = O(log(n)) 

// Here, n = the total number of elements which are present inside the input vector named "people" 