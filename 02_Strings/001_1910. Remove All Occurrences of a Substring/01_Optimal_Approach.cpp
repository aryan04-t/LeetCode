// LeetCode (1910. Remove All Occurrences of a Substring):
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/ 


#include<string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        size_t found = s.find(part);
        
        while(found != string::npos){
            s.erase(found, part.length());
            found = s.find(part);
        }

        return s;
    }
};


// T.C. = O(m) + ( (O(n/m) * ( O(n) + O(m) ) ) = O(m) + O(n^2/m) + O(n) = O(n^2/m)  
// -> (t.c. of find) + ( (while loop worst case iterations) * ( (t.c. of erase) + (t.c. of find) ) ) 

// S.C. = O(1) 

// Here, n = length of input string named "s", and m = length of input string named "part" 



/*


# Theoretically Approach-1 and 2 both have same time complexity, but still why Approach-2 is considered better in real world scenarios because: 


--> Approach-1 uses more functions than Approach-2, it uses 3 functions, substr(), compare(), and erase(), and that's why it involves multiple calls to these functions within a loop, and it leads to more function call overhead. 

--> In Approach-1 repetitive substring creation takes place, multiple string objects get created, and this leads to increase in cost. 

--> Because substr() function returns a string object and find() function returns size_t type data (an unsigned integral type), and returning and receiving a size_t data is more cost efficient than a string object. 

--> That's why use of find function in Approach-2 reduces the overhead associated with memory allocation and deallocation.

--> All these above facts make the Approach-2 code more efficient in terms of both time and space, in real world scenarios. 


*/



/*

@ References Cited: 

--> ChatGPT: https://chat.openai.com/ 
--> CPlusPlus (std::string::substr): https://cplusplus.com/reference/string/string/substr/ 
--> CPlusPlus (std::string::find): https://cplusplus.com/reference/string/string/find/ 

*/ 