// LeetCode (506. Relative Ranks): 
// https://leetcode.com/problems/relative-ranks/ 


#include<vector> 
#include<queue> 
#include<string> 
using namespace std; 


class MyPair{

    private: 
        int first; 
        int second; 

    public:
        
        MyPair() {} 
        MyPair(int _first, int _second) : first(_first), second(_second) {} 

        bool operator() (const MyPair* p1, const MyPair* p2) const{ 
            if(p1->first < p2->first) return true; 
            else if(p1->first > p2->first) return false;
            // else if(p1->first == p2->first){
            else{
                if(p1->second < p2->second) return true; 
                else if(p1->second > p2->second) return false; 
                // else if(p1->second == p2->second) return true; 
                else return true;
            }
        }

        friend class Solution;
};


class Solution {
public:

    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size(); 

        priority_queue<MyPair*, vector<MyPair*>, MyPair> maxHeap; 
        
        for(int i=0; i < n; i++){
            MyPair* p1 = new MyPair(score[i], i); 
            maxHeap.push(p1); 
        } 

        vector<string> ans(n, ""); 

        int rank = 1;
        while(!maxHeap.empty()){

            MyPair* p = maxHeap.top(); 
            maxHeap.pop(); 

            if(rank == 1) ans[p->second] = "Gold Medal"; 
            else if(rank == 2) ans[p->second] = "Silver Medal"; 
            else if(rank == 3) ans[p->second] = "Bronze Medal"; 
            else ans[p->second] = to_string(rank); 

            rank++; 
        }

        return ans; 
    }
};


// T.C. = O(n * log(n)) + O(n) + O(n * log(n)) = O(n * log(n)) 
// S.C. = O(n) + O(n) = O(2n) = O(n) 

// Here, n = the total number of integers which are present inside the input vector named "score" 