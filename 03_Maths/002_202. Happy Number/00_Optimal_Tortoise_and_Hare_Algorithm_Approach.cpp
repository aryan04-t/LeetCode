// LeetCode (202. Happy Number): 
// https://leetcode.com/problems/happy-number/ 


class Solution {
public:

    int sumOfDigitSquares(int n){

        int sum = 0;
        int digit;

        while(n){
            digit = n % 10; 
            sum += (digit * digit); 
            n /= 10; 
        }

        return sum;

    }

    bool isHappy(int n) {

        int slow = n;
        int fast = sumOfDigitSquares(n); 

        if(fast == 1) return true; 

        while(slow != fast){
            
            slow = sumOfDigitSquares(slow); 
            fast = sumOfDigitSquares(sumOfDigitSquares(fast)); 
            
            if(fast == 1) return true; 
        
        }

        return false;

    }

};


// T.C. = O(1) * O( 3 * (log(n) to the base 10) ) =  O(log(n) to the base 10) 
// S.C. = O(1) 

// Here, n = the value of input variable named "n" 

// Above used algorithm is known as "Tortoise and Hare Algorithm" and it is also known as "Floyd's Cycle Detection Algorithm" 