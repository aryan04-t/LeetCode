// LeetCode (2924. Find Champion II): 
// https://leetcode.com/problems/find-champion-ii 


#include<vector> 
using namespace std; 


class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> inEdgeCount(n, 0); 

        for (const vector<int> &edge: edges) {
            inEdgeCount[edge[1]]++; 
        }

        int strongestTeam = -1; 

        for (int i=0; i < n; i++) {
            int inDegree = inEdgeCount[i]; 
            if (inDegree == 0) {
                if (strongestTeam == -1) strongestTeam = i; 
                else {
                    strongestTeam = -1;
                    break;
                }
            }
        }

        return strongestTeam; 
    }
};


// T.C. = O(e + v) = O(e + n) 
// S.C. = O(v) = O(n) 

// Here, v = total number of vertices in DAG = n 
// and e = total number of edges in DAG = length of input vector named "edges" 