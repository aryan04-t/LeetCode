// LeetCode (165. Compare Version Numbers): 
// https://leetcode.com/problems/compare-version-numbers/ 


#include<string> 
using namespace std; 


class Solution {
public:
    int compareVersion(string version1, string version2) {

        int n = version1.length();
        int m = version2.length();

        int i = 0;
        int j = 0;

        while (i < n || j < m) {

            int ii = i, jj = j;

            while (ii < n && version1[ii] != '.') ii++;
            while (jj < m && version2[jj] != '.') jj++;

            int version1Revision = i < n ? stoi(version1.substr(i, ii - i)) : 0;
            int version2Revision = j < m ? stoi(version2.substr(j, jj - j)) : 0;

            if (version1Revision > version2Revision) return 1;
            else if (version1Revision < version2Revision) return -1;

            if (ii < n && version1[ii] == '.') ii++;
            if (jj < m && version2[jj] == '.') jj++;

            i = ii;
            j = jj;
        }

        return 0;
    }
};


// T.C. = O(max(n, m)) 
// S.C. = O(1) 

// Here, n = the length of input string named "version1", and m = the length of input string named "version2" 