// LeetCode (150. Evaluate Reverse Polish Notation): 
// https://leetcode.com/problems/evaluate-reverse-polish-notation/ 


#include<vector> 
#include<string> 
#include<stack> 
using namespace std; 


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size(); 
        stack<int> st; 

        for(int i=0; i < n; i++){

            if(tokens[i].size() == 1 && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/') ){
                
                int data2 = st.top();
                st.pop();
                
                int data1 = st.top();
                st.pop();   

                int newData;

                if(tokens[i][0] == '+'){
                    newData = data1 + data2;
                }
                else if(tokens[i][0] == '-'){
                    newData = data1 - data2;
                }
                else if(tokens[i][0] == '*'){
                    newData = data1 * data2;
                }
                else if(tokens[i][0] == '/'){
                    newData = data1 / data2;
                }

                st.push(newData);

            }
            else{
                int val = stoi(tokens[i]);
                st.push(val);
            }

        }

        int ans = st.top();

        return ans;

    }
};


// T.C. = O(n*m) -> t.c. of for loop * t.c. of stoi() function
// S.C. = O(n) 

// Here, n = total number of strings which are present inside the input vector named "tokens", and m = the average length of all numeral strings which are present inside the input vector "tokens" 