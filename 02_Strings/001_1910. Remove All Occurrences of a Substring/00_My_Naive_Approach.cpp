// LeetCode (Remove All Occurrences of a Substring):
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/ 


#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        int s_len = s.length();
        int part_len = part.length();

        for(int i=0; i < (s_len-(part_len-1)); i++){
            if(!((s.substr(i, part_len)).compare(part))){
                s.erase(i, part_len);
                s_len = s.length();
                i = -1;
            }
        }

        return s;
    }
};


// T.C.: O(n/m) * ( O(m) + O(m) + O(n) ) = O(2n) + O(n^2/m) + O(n/m) = O(n^2/m) 
// -> (worst case for loop iterations) * ( (substr t.c.) + (compare t.c.) + (erase t.c.) )

// S.C.: O(1) 

// Here, n = length of input string named "s", and m = length of input string named "part" 