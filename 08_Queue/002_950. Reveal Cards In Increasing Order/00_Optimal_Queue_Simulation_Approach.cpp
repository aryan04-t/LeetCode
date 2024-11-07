// LeetCode (950. Reveal Cards In Increasing Order): 
// https://leetcode.com/problems/reveal-cards-in-increasing-order/ 


#include<vector> 
#include<queue> 
#include<algorithm> 
using namespace std; 


class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        sort(deck.begin(), deck.end()); 

        int n = deck.size(); 
        vector<int> ans(n); 

        queue<int> q; 
        for(int i=0; i < n; i++) q.push(i); 

        for(int card : deck){
            
            int index = q.front(); 
            q.pop(); 
            
            ans[index] = card;
            
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};


// T.C. = O(n * log(n)) + O(n) + O(n) = O(n * log(n))
// S.C. = O(log(n)) + O(n) + O(n) = O(n) 

// Here, n = the number of elements which are present inside the input vector named "deck" 