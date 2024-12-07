// LeetCode (2337. Move Pieces to Obtain a String): 
// https://leetcode.com/problems/move-pieces-to-obtain-a-string 


class Solution {
public:

    void countCharFrequencies (const string &toBeIteratedStr, vector<int> &charFreqVec) {
        for (const char &ch : toBeIteratedStr) {
            if (ch == 'L')  charFreqVec[0]++; 
            else if (ch == 'R') charFreqVec[1]++; 
            else if (ch == '_') charFreqVec[2]++; 
        }
    }

    bool canChange (string start, string target) {

        vector<int> startCharFreqCounts(3, 0); 
        vector<int> targetCharFreqCounts(3, 0); 

        countCharFrequencies(start, startCharFreqCounts); 
        countCharFrequencies(target, targetCharFreqCounts); 

        if (
            startCharFreqCounts[0] != targetCharFreqCounts[0] 
            || 
            startCharFreqCounts[1] != targetCharFreqCounts[1] 
        ) return false; 

        int n = start.length(); 
        int i = 0, j = 0; 
        int totalLAndRChars = startCharFreqCounts[0] + startCharFreqCounts[1]; 

        while (totalLAndRChars--) {
            while (i < n && start[i] == '_') i++; 
            while (j < n && target[j] == '_') j++; 
            if (start[i] != target[j]) return false; 
            else {
                if (start[i] == 'L' && j > i) return false; 
                else if (start[i] == 'R' && j < i) return false; 
            } 
            i++, j++; 
        }

        return true; 
    }
};


// T.C. = O(n) + O(n) + O(2n) = O(4n) = O(n) 
// S.C. = O(3) + O(3) = O(1) 

// Here, n = the length of input string named "start" = the length of input string named "target" 