// LeetCode (717. 1-bit and 2-bit Characters): 
// https://leetcode.com/problems/1-bit-and-2-bit-characters 


#include<vector>
using namespace std;


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int n = bits.size();

        if (n == 1) return true;
        if (bits[n-2] == 0) return true;

        int consecutiveLeadingOnes = 0;
        
        int i=n-2;
        while (i >= 0 && bits[i] == 1) {
            consecutiveLeadingOnes++;
            i--;
        }

        bool isEven = !(consecutiveLeadingOnes & 1);
        bool isLastSpecialCharOneBit = isEven;

        return isLastSpecialCharOneBit;
    }
};


/*
    # Intuition: 
      - The last bit is always 0 (given constraint)
      - If bits[n-2] == 0, the array ends with a 1-bit character (return true)
        because 0 never starts a 2-bit character
      - If bits[n-2] == 1, we need to determine if this 1 pairs with the last 0
        or if it's already paired with a previous 1
      - Count consecutive 1s before the last index:
        * Even count → the 1 at bits[n-2] is unpaired → pairs with last 0 → 2-bit char (false)
        * Odd count → all 1s are paired → last 0 stands alone → 1-bit char (true)
      
    # Example:
      [1,1,1,0] → 3 consecutive leading ones for last index (odd ones) → pairs: (1,1)(1,0) → last char is 2-bit → false
      [1,0,1,1,0] → 2 consecutive leading ones for last index (even ones) → pairs: (1,0)(1,1) → last 0 alone → true
*/


// T.C. = O(n) -> Worst Case, but in Best Case it will be O(1) for this code 
// S.C. = O(1) 

// Here, n = the length of input vector named "bits" 