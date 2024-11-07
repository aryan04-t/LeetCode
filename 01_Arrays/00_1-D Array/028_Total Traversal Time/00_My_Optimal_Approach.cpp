// GeeksForGeeks (Total Traversal Time): 
// https://www.geeksforgeeks.org/problems/total-traversal-time/1 


#include<vector> 
#include<unordered_set> 
using namespace std; 


class Solution {
  public:
  
    int totalTime(int n, vector<int> &arr, vector<int> &penalty) {
        
        int totalTime = 0;
        unordered_set<int> st;
        
        st.insert(arr[0]);
        
        for(int i=1; i < n; i++){
            
            if(st.find(arr[i]) == st.end()){
                totalTime++; 
            }
            else{
                totalTime += penalty[arr[i]-1]; 
            }
            
            st.insert(arr[i]);
            
        }
        
        return totalTime;
        
    }
}; 


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = total number of elements which are present inside the input vector named "arr" = total number of elements which are present inside the input vector named "penalty" 