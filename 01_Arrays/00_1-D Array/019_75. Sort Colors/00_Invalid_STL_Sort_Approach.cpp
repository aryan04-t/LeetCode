// We have to solve this question without using in-built sort function LeetCode mentions this explicitly in the question summary, that's why this is an invalid approach here 

// But I just wanted to revisit Introsort concept that's why I just tried solving this question once by using STL's sort function 


#include<vector>
#include<algorithm> 
using namespace std;


class Solution {
public:

    void sortColors(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

    }

};


// T.C. = O(n*(log(n) to the base 2)) 
// S.C. = O(log(n) to the base 2)

// Introsort is used under the hood in C++'s STL sort function 
// Introsort is a sort which is a combination of (Quick Sort + Heap Sort + Insertion Sort) 

// Here, n = total number of elements which are present inside the input vector named "nums" 