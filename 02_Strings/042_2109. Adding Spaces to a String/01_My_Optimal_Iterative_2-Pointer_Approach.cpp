// LeetCode (2109. Adding Spaces to a String): 
// https://leetcode.com/problems/adding-spaces-to-a-string 


#include<string> 
using namespace std; 


class Solution {
public:

    string addSpaces(string s, vector<int>& spaces) {

        int i = 0, j = 0; 
        int n = s.length(), m = spaces.size(); 

        string ans = ""; 

        while (j < m) { 
            int toBeReachedIndex = spaces[j]; 
            while(i != toBeReachedIndex) {
                ans += s[i]; 
                i++; 
            }
            ans += ' '; 
            j++; 
            if (j == m) {
                while (i < n) ans += s[i++]; 
            }
        }

        return ans; 
    }
}; 


// T.C. = O(m + n) = O(2n) = O(n) 
// S.C. = O(2n) = (s.c. of ans string) = O(n) 

// Here, n = the length of input string named "s", and m = the total number of integers which are present inside the 1-D input vector named "spaces", in worst case m == n 


/*

# My 1st "Unordered Set and Iterative Approach" was also optimal, it also had same O(n) t.c. and O(n) s.c. but when I saw its runtime was 143ms and memory used was 121MB, I was upset that why it performed so badly. I realised that even if searching in an unordered_set has t.c average O(1) and in this case the spaces vector values are all unique and strictly increasing so these values inside the unordered_set will ideally never hit make the unordered_set hit worst case for value retrieval but still the unordered_set formation by hashing and value retrieval from it consumes time, and all this impacts the runtime and memory used in real life by my code 

# So, I was not gonna think of a new approach cuz I felt t.c. and s.c. wise my 1st approach was optimal, but after I saw that runtime was really bad, I didn't try to think of a new approach as I have already shut my logical brain down and I was convinced that "unordered_set approach" is one of the optimal solutions. So, I just saw the tags and then went to the solutions tab and there I saw a guy saying 4ms achievable in C++ and then when I got the conviction that a better runtime code can be written, I again restarted my logical brain and came up with this iterative 2-Pointer approach (I ran this code, I am not a fan of strict ms calculations at all, cuz it flickers anyways but it still gives a fair bit of idea about how your code's real life performance is with respect to other people's submissions, although you get this idea only after submitting the code 3-4 times when you're sure that LeetCode is giving a digestable output of runtime for your code and it is accurate. So, when I submitted this code for the 1st time it had a runtime of 11ms and memory used 85MB, and I was satisfied. 

DONE FOR THE DAY!!

*/