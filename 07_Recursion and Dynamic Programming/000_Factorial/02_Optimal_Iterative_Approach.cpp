#include<iostream>
using namespace std;


int factorial(int n){

    int fact = 1;
    
    for(int i = n; i > 1; i--){
        fact = i * fact;
    }

    return fact;

}


int main(){

    int n; 
    cout << "Enter n: "; 
    cin >> n; 

    cout << "Factorial of n = " << factorial(n);

}


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the value of input variable named "n" 