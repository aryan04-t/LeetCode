// LeetCode (415. Add Strings): 
// https://leetcode.com/problems/add-strings/ 


#include<vector> 
#include<string> 
using namespace std; 


class Solution {
public:
    string addStrings(string num1, string num2) {
        
        vector<int> number1; 
        vector<int> number2; 
        
        int len1 = num1.length();
        int len2 = num2.length();
 
        while(len1--){
            number1.push_back(num1[len1] - '0');
        }
        
        while(len2--){
            number2.push_back(num2[len2] - '0');
        }

        len1 = number1.size();
        len2 = number2.size();

        vector<int> resultNum;
        int digit;
        int carry = 0; 
        int sum;

        int i=0;
        for(; i < len1 && i < len2; i++){
            sum = number1[i] + number2[i] + carry;
            digit = sum % 10;
            carry = sum / 10;
            resultNum.push_back(digit);
        }

        if(i == len1){
            while(i < len2){
                sum = number2[i] + carry;
                digit = sum % 10;
                carry = sum / 10;
                resultNum.push_back(digit);
                i++;
            }
        }

        if(i == len2){
            while(i < len1){
                sum = number1[i] + carry;
                digit = sum % 10;
                carry = sum / 10;
                resultNum.push_back(digit);
                i++;
            }
        }

        if(carry){
            resultNum.push_back(1);
        }

        int n = resultNum.size();
        string result = "";

        for(int i = n-1; i >= 0; i--){
            result.push_back(resultNum[i] + '0');
        }

        return result;
    }
};


// T.C. = O(max(n,m)) 
// S.C. = O(max(n,m)) 

// Here, n = length of input string named "num1", and m = length of input string named "num2" 