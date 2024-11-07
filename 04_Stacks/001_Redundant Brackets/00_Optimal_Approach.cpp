// Coding Ninjas (Redundant Brackets): 
// https://www.codingninjas.com/studio/problems/redundant-brackets_975473 


#include<string>
#include<stack> 
using namespace std;


bool findRedundantBrackets(string &s){

    int stringLen = s.length();

    stack<char> st;

    for(int i=0; i < stringLen; i++){
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            st.push(s[i]);
        }
        else{
            if(s[i] == ')'){
                if(!st.empty()){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                        st.pop();
                        while(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                            st.pop();
                        }
                        if(st.top() == '('){
                            st.pop();
                        }
                    }
                    else{
                        return true;
                    }
                }
                else{
                    return true;
                }
            }
        }
    }

    if(!st.empty()){
        while(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
            st.pop();
            if(st.empty()){
                break;
            }
        }
    }

    return (st.empty()) ? false : true;

}


// T.C. = ( O(n) * O(1) ) + O(n) = O(n) 
// -> ( (t.c. of for loop which is iterating over whole input string once) * (average t.c. of nested while loop) ) + (worst case t.c. of outer while loop) 

// S.C. = O(n) 

// Here, n = length of input string named "s" 