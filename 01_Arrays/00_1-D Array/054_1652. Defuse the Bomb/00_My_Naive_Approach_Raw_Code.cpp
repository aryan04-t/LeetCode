// LeetCode (1652. Defuse the Bomb): 
// https://leetcode.com/problems/defuse-the-bomb 


#include<vector> 
using namespace std;  


class Solution {
public:

    vector<int> decrypt(vector<int>& code, int k) {
        
        int n = code.size(); 
        if(k == 0) return vector<int>(n, 0); 

        vector<int> decryptAns(n, 0); 

        for (int i=0; i < n; i++) {
            int j = i, sum = 0, tempK = k; 
            if (k > 0) {
                j = i+1; 
                while (tempK--) {
                    if (j == n) j = 0; 
                    sum += code[j]; 
                    j++; 
                }
            }
            else {
                j = i-1; 
                while (tempK++) {
                    if (j == -1) j = n-1; 
                    sum += code[j]; 
                    j--; 
                }
            }
            decryptAns[i] = sum; 
        }

        return decryptAns; 
    }
};


// T.C. = O(n*k) 
// S.C. = O(n) 

// Here, n = the length of 1-D input vector named "code", and k = the value of input integer k 