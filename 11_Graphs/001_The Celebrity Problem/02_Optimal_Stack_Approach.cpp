// GeeksForGeeks (The Celebrity Problem): 
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1 


#include<vector> 
#include<stack> 
using namespace std; 


class Solution {
public:

    int celebrity(vector<vector<int>> &M, int n){
        
        stack<int> st;
        for(int i=0; i < n; i++){
            st.push(i); 
        }

        while(st.size() != 1){
            
            int a = st.top(); 
            st.pop(); 
            
            int b = st.top(); 
            st.pop(); 
            
            if(M[a][b] == 1) st.push(b); 
            else if(M[b][a] == 1) st.push(a); 
        }   
        
        int celebrity = st.top(); 
        st.pop(); 
        
        for(int j=0; j < n; j++){
            if(M[celebrity][j] != 0) return -1; 
        }
        
        for(int i=0; i < n; i++){
            if(i == celebrity) continue; 
            if(M[i][celebrity] == 0) return -1; 
        }
        
        return celebrity; 
    }
};


// T.C. = O(n) + O(n-1) + O(n)  + O(n) = O(4n-1) = O(n) 
// S.C. = O(n) 

// Here, n = the total number of people who are present in the party = the value of input variable named "n" 
