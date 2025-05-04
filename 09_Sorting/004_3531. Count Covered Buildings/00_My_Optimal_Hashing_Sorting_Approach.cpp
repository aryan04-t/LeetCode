// LeetCode (3531. Count Covered Buildings): 
// https://leetcode.com/problems/count-covered-buildings 


#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


class Solution {
public:
    
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        unordered_map<int, vector<int>> xAxisMp;
        unordered_map<int, vector<int>> yAxisMp;
        
        for (const vector<int> &v : buildings) {
            xAxisMp[v[0]].push_back(v[1]);
            yAxisMp[v[1]].push_back(v[0]);
        }

        for (pair<const int, vector<int>> &p : xAxisMp) {
            sort(p.second.begin(), p.second.end()); 
        }
        
        for (pair<const int, vector<int>> &p : yAxisMp) {
            sort(p.second.begin(), p.second.end()); 
        }

        int coveredBuildings = 0;
        
        for (const vector<int> &v : buildings) {
            
            bool coveredInXAxis = false, coveredInYAxis = false;
            int x = v[0], y = v[1]; 
            
            const vector<int> &yCoords = xAxisMp[x]; 
            int yCoordsSize = yCoords.size();
            
            if (yCoordsSize > 2 && yCoords[0] != y && yCoords[yCoordsSize-1] != y) {
                coveredInYAxis = true;
            }
            
            const vector<int> &xCoords = yAxisMp[y]; 
            int xCoordsSize = xCoords.size();
            
            if (xCoordsSize > 2 && xCoords[0] != x && xCoords[xCoordsSize-1] != x) {
                coveredInXAxis = true;
            }

            if (coveredInXAxis && coveredInYAxis) coveredBuildings++;
        }

        return coveredBuildings; 
    }
};


// T.C. = O(m) + 2*(O(m) + O(m*log(m) to the base 2)) + O(m) = O(m*log(m)) 
// S.C. = O(2m) + O(2m) = O(m) 

// Here, m = the length of input array named "buildings" 