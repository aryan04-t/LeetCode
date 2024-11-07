// LeetCode (2352. Equal Row and Column Pairs): 
// https://leetcode.com/problems/equal-row-and-column-pairs/ 


#include<vector> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:

    class VectorHash{
        public: 
            // Although this is a really bad hash function, because hash functions try to distribute the hash values evenly and they also try to reduce number of collisions as much as possible 
            // There can be better ways for writing this hash function so that the generated hash values result least collisions, but my naive mind was able to come up with this only for now 
            int operator()(const vector<int> &v) const{
                int hash = 0; 
                for(int val : v) hash += val; 
                return hash; 
            }
    };

    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size(); 
        // There is no predifined hash function in C++ STL for vector to be hashed as a key in the hash map, that's why I created one on my own 
        unordered_map<vector<int>, int, VectorHash> mp; 
        for(int i=0; i < n; i++) mp[grid[i]]++; 

        int count = 0; 

        for(int j=0; j < n; j++){
            vector<int> temp(n, 0); 
            for(int i=0; i < n; i++){
                temp[i] = grid[i][j]; 
            }
            count += mp[temp]; 
        }

        return count; 
    }
};


// T.C. = O(n^2) + O(n * 3n) = O(n^2) 
// S.C. = O(n^2) 

// Here, n = the total number of 1-D vectors which are present inside the given input 2-D vector = total number of columns which are present inside each 1-D vector of the given input input 2-D vector 

// Note: Mostly the once in a blue moon worst case of hash maps doesn't really gets hit, but if all the hash values turn out to be same, then the worst case of unordered_map gets hit and in that case for this question the worst case time complexity will go till O(n^3), and the chance of happening this are even more because my hash function isn't that good in spreading the hash values, but yeahh, this the best solution time complexity wise as per me 