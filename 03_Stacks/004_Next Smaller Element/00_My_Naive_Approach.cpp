// Coding Ninjas (Next Smaller Element): 
// https://www.codingninjas.com/studio/problems/next-smaller-element_1112581 


// Naive Approach: 


#include<vector>
using namespace std;


vector<int> nextSmallerElement(vector<int> &arr, int n)
{

    vector<int> result(n, -1);

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[i]){
                result[i] = arr[j];
                break;
            }
        }
    }

    return result;
}


// T.C. = O(n^2) -> (due to nested for loops) 
// S.C. = O(n) 

// Here, n = number of elements which are present in input vector named "arr" 