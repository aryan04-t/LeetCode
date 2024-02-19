// LeetCode (12. Integer to Roman): 
// https://leetcode.com/problems/integer-to-roman/ 


#include<string> 
#include<vector> 
using namespace std; 


class Solution {
public:

    string intToRoman(int num) {
        
        string roman = "";

        vector<pair<int, string>> v { {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} };

        for(int i=0; i < 13; i++){
            while(num >= v[i].first){
                roman += v[i].second;
                num -= v[i].first;
            }
        }

        return roman;

    }
}; 


// T.C. = O(13) * O(n) = O(n) 
// S.C. = O(13) + O(n) = O(n) 

// Here, n = the total number of digits which are present inside the input number named "num" 