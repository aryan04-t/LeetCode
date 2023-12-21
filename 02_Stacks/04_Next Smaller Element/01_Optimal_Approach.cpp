// Coding Ninjas (Next Smaller Element): 
// https://www.codingninjas.com/studio/problems/next-smaller-element_1112581 


// Optimal Approach: 

#include<iostream> 
#include<vector> 
#include<stack> 
using namespace std; 


vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);

    vector<int> result(n);

    for(int i = n-1; i >= 0; i--){
        
        while(st.top() >= arr[i]){
            st.pop();
        }

        result[i] = st.top();
        st.push(arr[i]);

    }

    return result;
}


// T.C.: O(n) * O(1) = O(n) -> (t.c. of for loop for traversing the whole input vector once) * (average t.c. of while loop even in wrost case is constant) 

// S.C.: O(n) + O(n) = O(2n) = O(n) -> (worst case s.c. of vector named "result") + (worst case s.c. of stack named "st") 

// Here, n = number of elements which are present in input vector named "arr" 