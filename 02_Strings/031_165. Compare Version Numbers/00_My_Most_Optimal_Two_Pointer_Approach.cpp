// LeetCode (165. Compare Version Numbers): 
// https://leetcode.com/problems/compare-version-numbers/ 


#include<string> 
using namespace std; 


class Solution {
public:

    int compareVersion(string version1, string version2) {
        
        int ans = 0; 
        int n = version1.length(), m = version2.length();
        int i=0, j=0;

        while(i < n || j < m){

            int num1 = 0; 
            while(i < n && version1[i] != '.'){
                num1 = num1 * 10 + int(version1[i] - '0'); 
                i++;
            }

            int num2 = 0; 
            while(j < m && version2[j] != '.'){
                num2 = num2 * 10 + int(version2[j] - '0'); 
                j++; 
            }

            if(num1 < num2){
                ans = -1; 
                break; 
            }
            else if(num1 > num2){
                ans = 1; 
                break; 
            }

            i++; 
            j++; 
        }

        return ans; 
    }
};


// T.C. = O(max(n, m)) 
// S.C. = O(1) 

// Here, n = the length of the input string named of "version1", and m = the length of the input string named "version2" 