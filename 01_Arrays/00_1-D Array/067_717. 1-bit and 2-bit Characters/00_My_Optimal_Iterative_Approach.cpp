// LeetCode (717. 1-bit and 2-bit Characters): 
// https://leetcode.com/problems/1-bit-and-2-bit-characters 


#include<vector>
using namespace std;


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        char ch = '-';
        int n = bits.size();

        int i = 0;
        while(i < n) {
            int currBit = bits[i];
            if (currBit == 1) {
                ch = 'b';
                i += 2;
            }
            else if (currBit == 0) {
                ch = 'a';
                i++;
            }
        }

        return (ch == 'a');
    }
};


/*
    # Intuition: 
      - I just represented both special characters 1-bit and 2-bit with 'a' and 'b' respectively 
      - And I just simulated the conditions, processing the bits array left to right and storing the currently processed special char in the "ch" variable 
      - At the end the last processed character is stored in "ch" variable, based on that I can determine my answer 
*/


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input vector named "bits" 