// LeetCode (2232. Minimize Result by Adding Parentheses to Expression): 
// https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/ 


#include<string>
using namespace std; 


class Solution {
public:

    void evaluate(const string &num1, const string &num2, int k, int j, int &mini, int &leftParenIndex, int &rightParenIndex){

        int m1 = num1.length(); 
        int m2 = num2.length(); 

        int num1Part1 = (num1.substr(0, k) == "") ? 1 : stoi(num1.substr(0, k)); 
        int num1Part2 = stoi(num1.substr(k, m1-k)); 

        int num2Part1 = stoi(num2.substr(0, j+1)); 
        int num2Part2 = (num2.substr(j+1, m2-j-1) == "") ? 1 : stoi(num2.substr(j+1, m2-j-1)); 

        int temp =  num1Part1 * (num1Part2 + num2Part1) * num2Part2; 

        if(temp < mini){
            mini = temp;
            leftParenIndex = k;
            rightParenIndex = m1 + 1 + j + 2;
        }
    }

    string minimizeResult(string s) {
        
        int n = s.length(); 
        
        int i = 0; 
        while(i < n){
            if(s[i] == '+') break;
            i++; 
        } 

        string num1 = s.substr(0, i); 
        string num2 = s.substr(i+1, n-i-1); 

        int m1 = num1.length();
        int m2 = num2.length();

        int leftParenIndex; 
        int rightParenIndex; 
        int mini = INT_MAX; 

        i = 0; 
        int j = m2-1; 

        while(i < m1 && j >= 0){

            int k = i;
            while(k < m1){
                evaluate(num1, num2, k, j, mini, leftParenIndex, rightParenIndex); 
                k++; 
            }

            k = j; 
            while(k >= 0){
                evaluate(num1, num2, i, k, mini, leftParenIndex, rightParenIndex);
                k--;
            }

            i++;
            j--;
        }

        string ans(n+2, ' '); 
        ans[leftParenIndex] = '('; 
        ans[rightParenIndex] = ')'; 
        
        i = 0;
        j = 0;
        while(i < n+2){
            if(i == leftParenIndex || i == rightParenIndex){
                i++; 
                continue; 
            } 
            ans[i++] = s[j++]; 
        }

        return ans; 

    }
};


// T.C. = O(n) + O(n) + O(n/2 * ((n/2 * n) + (n/2 * n))) + O(n+2) = O(n^3) 
// S.C. = O(n/2) + O(n/2) + O(n+2) = O(n) 

// Here, n = the length of input string named "s" 