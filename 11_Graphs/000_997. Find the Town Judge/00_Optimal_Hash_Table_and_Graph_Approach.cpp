// LeetCode (997. Find the Town Judge): 
// https://leetcode.com/problems/find-the-town-judge/ 


#include<vector> 
using namespace std;


class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> inDegree(n+1); 
        vector<int> outDegree(n+1); 

        for(const vector<int> &v : trust){
            int e1 = v[0]; 
            int e2 = v[1]; 
            outDegree[e1]++; 
            inDegree[e2]++; 
        }

        int townJudge = -1; 
        for(int i=1; i < n+1; i++){
            if(inDegree[i] == n-1 && outDegree[i] == 0){
                townJudge = i;
                break;
            }
        }

        return townJudge;
    }
};


// T.C. = O(e) + O(v) = O(v + e) 
// S.C. = O(v + 1) + O(v + 1) = O(2v + 2) = O(v) 

// Here, v = the total number of people in the town = n = the total number of vertices in the graph, 
// and e = the total number of edges in the graph = the total number of 2 sized vectors which are present inside the input 2-D vector named "trust" 