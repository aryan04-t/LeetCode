// LeetCode (8. String to Integer (atoi)): 
// https://leetcode.com/problems/string-to-integer-atoi/ 


#include<string> 
using namespace std; 


class Solution {
public:

    int myAtoi(string s) {


        int n = s.length(); 
        int i = 0; 

        while(i < n && s[i] == ' ') i++; 
        if(i == n) return 0; 


        int isPositive = true; 
        if(s[i] == '-'){
            isPositive = false; 
            i++;
        } 
        else if(s[i] == '+') i++;


        while(i < n && s[i] == '0') i++;
        if(i == n) return 0; 


        int j = i;
        while(j < n && s[j] >= '0' && s[j] <= '9'){
            j++;
        }
        

        string number = s.substr(i, j-i);

        int m = number.length();
        int num = 0; 
        
        if(m >= 11){ 
            if(isPositive) return INT_MAX; 
            else return INT_MIN; 
        } 
        else if(m < 10){
            
            int k = 0;
            while(k < m){
                num = num*10 + int(number[k] - '0');
                k++;
            }
        
            if(isPositive) return num; 
            else return (-1 * num); 

        }
        else if(m == 10){
            
            if(isPositive){

                int k = 0;
                while(k < 9){
                    num = num*10 + int(number[k] - '0');
                    k++;
                }

                if( num < INT_MAX/10){
                    num = num*10 + int(number[k] - '0');
                    return num;
                }
                else if( num == INT_MAX/10  && (number[k] - '0') <= 7 ){
                    num = num*10 + int(number[k] - '0');
                    return num;
                }
                else{
                    return INT_MAX;
                }

            }
            else{

                int k = 0; 
                while(k < 9){
                    num = num*10 - int(number[k] - '0');
                    k++;
                }

                if( num > INT_MIN/10 ){
                    num = num*10 - int(number[k] - '0');
                    return num;
                }
                else if( num == INT_MIN/10  && (number[k] - '0') <= 8 ){
                    num = num*10 - int(number[k] - '0');
                    return num;
                }
                else{
                    return INT_MIN;
                }

            }

        }

        return num;        

    }
};


// T.C. = processing input string + t.c. of substr() function = O(n) + O(m) = O(n) 
// S.C. = O(m) 

// Here, n = the length of the input string named "s", and m = the length of the valid number sequence which has to be processed 