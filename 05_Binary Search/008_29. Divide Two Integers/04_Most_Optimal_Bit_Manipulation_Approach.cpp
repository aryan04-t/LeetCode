// 29. Divide Two Integers (29. Divide Two Integers): 
// https://leetcode.com/problems/divide-two-integers/ 


#include<limits.h> 
#include<cstdlib> 
using namespace std; 


class Solution {
public:

    int divide(int dividend, int divisor) {

        if(dividend == 0) return 0;
        if(dividend == divisor) return 1; 
        if(dividend == INT_MIN && divisor == -1) return INT_MAX; 

        bool isPositive = ((dividend < 0) == (divisor < 0)); 
        // int sign = (dividend > 0) ^ (divisor > 0) == 0 ? 1 : -1; 

        unsigned int dvd = abs(dividend); 
        unsigned int dvs = abs(divisor); 
        unsigned int result = 0; 

        while(dvd >= dvs){
            unsigned int temp = dvs; 
            unsigned int mul = 1; 
            while((temp << 1) < dvd){
                temp <<= 1;
                mul <<= 1;
            }
            dvd -= temp;
            result += mul;
        } 

        return (isPositive) ? result : -result; 
        // return (sign == -1) ? -result : result; 
    }
};


// T.C. = O(log(n) * log(n)) -> (Dry run the worst case to verify this time complexity, worst case is: dividend = INT_MIN and divisor = 1) 
// S.C. = O(1) 

// Here, n = the value of input variable named "dividend" 



/*

# Introduction to "Bit Manipulation" and "Divison Formula": 
    --> Well if you know how to play with bits and bitwise operators then understaning my code by dry running it won't be a problem for you  
    --> If you know how how to play with power of 2, left shift operator and if you know the divison formula (dividend = divisor * quotient + remainder) then understanding my approach's intuition will also not be a problem for you

@ But if you have any problem in understanding above written things then you don't know bit manipulation and you're not in touch with basic mathematics fundamentals: 
    --> No problem, to understand the above concepts for this question you can refer this person's explanation of "bit manipulation" and the use of "division formula" 

Reference: https://leetcode.com/problems/divide-two-integers/solutions/1516367/complete-thinking-process-intuitive-explanation-all-rules-followed-c-code/



# Now let's understand the intuition behind my above code's base cases and looping conditions: 


0. Reading and Understanding Constraints of the Question: 
    --> The constraints say divisor will never be 0, so no need to handle that case (Because we all know, dividing any number by 0 is undefined, as it is not a valid mathematical expression) 
    --> Now the dividend and divisor will be in the range of INT_MIN to INT_MAX 

1. Understanding 1st two base cases: 
    --> We know dividend can be 0 and if you divide 0 by anything, we know we always get 0, so that's why this is our 1st base case 
    --> When we have to divide 2 numbers, the 2nd basic intuition that we all can have is that if the dividend and divisor are same, then the output will always be 1 
    --> Now here comes the main part of code, we skip the 3rd base case for now, because its intuition cannot be justified directly right now

2. Determining the Sign of Output: 
    --> When we think of solving the problem and we understand that the values can be positive and negative both, and we don't want to handle all +ve and -ve combinations of dividend and divisor differently, that's why we spot a pattern and try to generalize our approach 
    --> If we have dividend and divisor both either negative togther or poistive togther, then the answer will be always positive and if the signs of dividend and divisor are opposite then the output will be always negative 
    --> So, if we just take absolute values of divisor and dividend both, and then we just have to calculate the answer using thes absolute values and we can just give the final answer the valid sign +ve or -ve as per the pattern that we spotted above 
    --> That's why just to determine the final sign of our ouput, we have used a boolean flag and we have implemented the logic of our critical observation in front of that boolean flag 

3. Converting dividend and divisor into Absolute Values: 
    --> So, now we want to take absolute values of dividend and divisor so that we can implement the dividing logic on them 
    --> But if we try to take absolute value of INT_MIN, we will get 2^31, and this is not a valid value which can we stored in the signed int beacuse signed int have a range of -2^31 to 2^31-1, we can handle this overflow using "long long int" datatype, but the question mentions not to use a 64bit datatype, we only have 32bit datatypes to compute the output 
    --> So, that's why we will use unsigned int, here the sign bit of the signed int can also be used to store valid values and hence we have a storing capacity of 0 to 2^32-1 in a unsigned int  
    --> Now we take the absolute values of "dividend" and "divisor" and we store them in unsigned int datatypes 

4. Understading 3rd Base Case: 
    --> While taking the absolute values of dividend and divisor, we understood that INT_MIN will be the one which is going to cause us most of the problems 
    --> So, now we have stored the values in "unsigned int" when we want to compute the output, but we have to return the answer in signed int datatype only 
    --> And due to this reason we try to find the edge case with respect to INT_MIN where the output can get overflow
    --> And then we're able to spot the test case that when dividend will be == INT_MIN and divisor will be == -1 the output will be out of the range of signed int. We have to handle this overflow here and we have to return INT_MAX in this case, that's why we handle this one and only overflow case by writing a base case 

5. Understanding Outer While Loop: 
    --> The outer while loop is based on the basic logic of dividing, we know that if the dividend is greater than or equal to divisor then only we have to perform the divison, else the answer will always be zero when the divisor is greater than the dividend (We're ony calculating the whole number part of our answer here, we're not calculating the decimal part that's why the outer loop has a condition while(dvd >= dvs) is true, iterate inside the outer loop)  

6. Understanding Inner While Loop: 
    --> Well the inner while loop just tries to use the left shift operator to increment the divisor by multiplying it with 2 each time until the divisor stays smaller than dividend 
    --> One common intuition would be to increment the divisor's value by left shifting until it is less than or equal to dividend 
    --> We can also keep the inner while loop conditon as while((temp << 1) <= dvd), but problem with this condition is again concerned with the absolute value of INT_MIN 
    --> If the inner while loop's condition is kept to be while((temp << 1) <= dvd), then the edge cases that will get stuck here are the once which have dvd = abs(INT_MIN) 
    --> When dvd = abs(INT_MIN), and dvs = 1,2,4,8,16,32,...,2^31, inside the inner loop the temp will always approach 2^31 by getting left shifted and the inner loop will become infinite when 2^31 value is attained by temp 
    --> Because when temp becomes 2^30, in next while loop iteration the condition will check while( (2^30 << 1) <= 2^31) the answer will be true because of the equal to sign and the temp will become 2^31, and now the problem occurs, while( (2^31) << 1) <= 2^31) the answer is true, because in the case of a 32bit unsigned int when you left shift 2^31, in the binary representation of 2^31 the only one is present at the MSB and that one also gets removed when we left shift 2^31, and the temp becomes becomes 0, and the inner while loops enter infinite loop

    --> That's why we cannot let temp ever reach the value of 2^31, because if we left shift 2^31 in a 32bit unsigned int then we get 0. 

    --> And this is the reason the inner loop condition will be while((temp << 1) < dvd), we cannot keep equal to symbol here, if we were allowed use "long long int" then we could have kept the inner while loop's condition with the equal to sign, and if we were able to keep the equal to sign in our inner while loop's condition then our code's time complexity would have been O(log(n)), but just because we cannot use "long long int" and we have to just deal with 32bit dataypes, we're not able to put the equal to symbol in the inner loop's condition. And because of this reason, the time complexity of our code has become O(log(n)*log(n)) 

7. Now as both the loops end, we have handled all the edge cases, we have got our answer, we just have to put the correct sign to our answer and return it, we don't have to typecast the unsigned int into the signed int explicitly, we can either return the answer directly just like I did in my code, both signed and unsigned int are 4 bytes, so the compiler handles the implicit types casting of unsigned int to signed int when I am adding a minus sign to the unsigned int and the function is expecting a signed int value to return. 

8. But if you want to store the value in a variable 1st before you return the answer, then you can write this code: 

        int ans;
        if(isPositive){
            ans = result;
        }
        else{
            ans = -result; 
        }

    --> here also the implicit typecasting will take place, if you want then you can write unnecessary explicit typecasting code also 

        int ans;
        if(isPositive){
            ans = result;
        }
        else{
            ans = (int)-result; 
        }

    --> and if you're someone who cries whenever someone uses C typecasting ways in C++, then you can also do this unnecessary explicit typecasting using C++ typecasting method 

        int ans;
        if(isPositive){
            ans = result;
        }
        else{
            ans = static_cast<int>(-result);  
        }

# At the end just return the ans and finish your code. 

*/