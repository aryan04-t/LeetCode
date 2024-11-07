// This is not a LeetCode Question, I am just doing it to get a grip on recursion fundamentals and to practice finding time complexity of recursion. 


#include<iostream>
using namespace std;


int factorial(int n){

    if(n == 0 || n == 1) return 1;

    return n * factorial(n-1);

}


int main(){

    int n; 
    cout << "Enter n: "; 
    cin >> n; 

    cout << "Factorial of n = " << factorial(n);

}


// T.C. = O(n) 
// S.C. = O(n) -> This space complexity is caused due to function call stack 

// Here, n = the value of input variable named "n" 