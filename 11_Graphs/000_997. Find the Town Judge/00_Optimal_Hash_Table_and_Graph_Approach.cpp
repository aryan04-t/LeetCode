// LeetCode (997. Find the Town Judge): 
// https://leetcode.com/problems/find-the-town-judge/ 


#include<vector> 
using namespace std;


class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> in(n+1);
        vector<int> out(n+1); 

        int m = trust.size();

        for(int i=0; i < m; i++){
            out[trust[i][0]]++;
            in[trust[i][1]]++;
        }

        for(int i=1; i < n+1; i++){
            if(out[i] == 0 && in[i] == n-1){
                return i;
            }
        }

        return -1;

    }
};


// T.C. = O(max(n, m)) 
// S.C. = O(n+1) + O(n+1) = O(n) 

// Here, n = the value of input variable "n", and m = the size of 2-D input vector "trust" 