// LeetCode (2490. Circular Sentence): 
// https://leetcode.com/problems/circular-sentence 


class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        int n = sentence.length(); 

        if (n == 1 && n != ' ') return true; 
        else if (n == 1 && n == ' ') return false; 
        else if (sentence[0] == ' ' || sentence[n-1] == ' ') return false; 

        int i = 0; 
        bool isCircular = true; 

        while (i < n) {
            if (i == n-1) {
                if (sentence[i] != sentence[0]) isCircular = false; 
            }
            else if (sentence[i] == ' ') {
                if (sentence[i-1] != sentence[i+1]) isCircular = false;
            }
            if (isCircular == false) break; 
            i++; 
        }

        return isCircular; 
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input string named "sentence" 