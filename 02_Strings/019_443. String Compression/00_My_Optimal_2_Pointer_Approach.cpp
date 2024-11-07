// LeetCode (443. String Compression): 
// https://leetcode.com/problems/string-compression/ 


#include<vector> 
#include<string> 
using namespace std; 


class Solution {
public:

    int compress(vector<char>& chars) {
        
        int n = chars.size(); 
        
        if(n == 1){
            return 1;
        }
        
        int i = 0; 
        int count = 1;

        int j = 0;

        for(; j < n-1; j++){
            if(chars[j] == chars[j+1]){
                count++;
            }
            else{
                
                chars[i++] = chars[j];
                
                if(count != 1){

                    string countStr = to_string(count); 
                    int m = countStr.length(); 
                    
                    for(int k=0; k < m; k++){
                        chars[i++] = countStr[k]; 
                    }
        
                }

                count = 1; 

            }
        }

        chars[i++] = chars[j]; 

        if(count != 1){
                    
            string countStr = to_string(count);
            int m = countStr.length();

            for(int k=0; k < m; k++){
                chars[i++] = countStr[k];
            }

        }

        return i;    

    }

};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the number of characters which are present inside the input char vector named "chars" 