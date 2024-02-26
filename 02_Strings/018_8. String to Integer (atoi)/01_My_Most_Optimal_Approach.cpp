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
        

        int m = j-i;
        int num = 0; 
        
        if(m >= 11){ 
            if(isPositive) return INT_MAX; 
            else return INT_MIN; 
        } 
        else if(m < 10){
            
            int k = i;
            while(k < j){
                num = num*10 + int(s[k] - '0');
                k++;
            }
        
            if(isPositive) return num; 
            else return (-1 * num); 

        }
        else if(m == 10){
            
            if(isPositive){

                int k = i;
                while(k < j-1){
                    num = num*10 + int(s[k] - '0');
                    k++;
                }

                if( num < INT_MAX/10){
                    num = num*10 + int(s[k] - '0');
                    return num;
                }
                else if( num == INT_MAX/10  && (s[k] - '0') <= 7 ){
                    num = num*10 + int(s[k] - '0');
                    return num;
                }
                else{
                    return INT_MAX;
                }

            }
            else{

                int k = i; 
                while(k < j-1){
                    num = num*10 - int(s[k] - '0');
                    k++;
                }

                if( num > INT_MIN/10 ){
                    num = num*10 - int(s[k] - '0');
                    return num;
                }
                else if( num == INT_MIN/10  && (s[k] - '0') <= 8 ){
                    num = num*10 - int(s[k] - '0');
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


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of the input string named "s" 