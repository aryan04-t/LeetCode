// LeetCode (791. Custom Sort String): 
// https://leetcode.com/problems/custom-sort-string 


#include<vector> 
#include<string> 
#include<algorithm> 
using namespace std; 


class Solution {

private:
    static inline vector<int> charPower = vector<int>(26, 26); 

    void buildCharPowerVec (const string &order) {
        short power = 0; 
        for (const char &c : order) {
            charPower[c - 'a'] = power++; 
        }
    }

    static bool comparator (const char &first, const char &second) {
        return (charPower[first - 'a'] < charPower[second - 'a']); 
    }

public:
  
    string customSortString(string order, string s) {

        buildCharPowerVec(order); 
        sort(s.begin(), s.end(), comparator); 

        return s; 
    }
};


// T.C. = O(26) + O(n*log(n)) = O(n*log(n)) 
// S.C. = O(26) + O(log(n)) -> C++ Intro-Sort takes log(n) space in worst case 

// Here, n = the length of input string named "s" 