// LeetCode (1456. Maximum Number of Vowels in a Substring of Given Length): 
// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length 


#include<string>
#include<limits.h> 
#include<algorithm>
using namespace std;


class Solution {
public:

    bool isVowel(const char &c){

        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u'){
            return true;
        }

        return false;

    }

    int maxVowels(string s, int k) {
        
        int ans = INT_MIN;
        int count = 0;

        for(int i=0; i < k; i++){

            if(isVowel(s[i])) count++;

        }

        ans = max(ans, count);
        
        int n = s.length();
        int j = 0;

        for(int i=k; i < n; i++){

            if(isVowel(s[j])) count--;
            if(isVowel(s[i])) count++;

            ans = max(ans, count);
        
            j++;
        }

        return ans;

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input string named "s" 