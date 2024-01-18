// LeetCode (415. Add Strings): 
// https://leetcode.com/problems/add-strings/ 


#include<vector> 
#include<string> 
using namespace std; 


class Solution {
public:

    void findSum(string &num1, string &num2, string &result){

        int digit1, digit2;
        int sum;
        int sumDigit;
        int carry = 0; 
        
        int len1 = num1.size();
        int len2 = num2.size();
        int i=0; 

        while(i < len1 || i < len2 || carry == 1){ 
            
            digit1 = (i < len1) ? (num1[i] - '0') : 0; 
            digit2 = (i < len2) ? (num2[i] - '0') : 0; 
            
            sum = digit1 + digit2 + carry;
            sumDigit = sum % 10;
            carry = sum / 10;
            
            result.push_back(sumDigit + '0');
            
            i++;
        }

    }

    string addStrings(string num1, string num2) {
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string result = "";
        findSum(num1, num2, result);

        reverse(result.begin(), result.end());

        return result;
    }

};


// T.C. = O(max(n,m)) 
// S.C. = O(max(n,m)) 

// Here, n = length of input string named "num1", and m = length of input string named "num2" 