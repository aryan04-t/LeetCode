// GeeksForGeeks (Bottom View of Binary Tree): 
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1 


#include<vector>
#include<map> 
#include<queue>
#include<utility> 
using namespace std; 


struct Node{
    int data;
    Node* left;
    Node* right;
};


// - - - - - - - - - - 


/*

struct Node{
    int data;
    Node* left;
    Node* right;
};

*/


class Solution {
public:

    vector <int> bottomView(Node *root) {
        
        int horizontalDist = 0; 
        
        queue<pair<Node*, int>> q; 
        q.push({root, horizontalDist}); 
        
        map<int, int> mp; 
        vector<int> ans;
        
        
        while(!q.empty()){
            
            pair<Node*, int> currPair = q.front(); 
            q.pop(); 
            
            Node* currNode = currPair.first; 
            int horizontalDist = currPair.second; 
            
            mp[horizontalDist] = currNode->data; 
            
            if(currNode->left != nullptr) q.push({currNode->left, horizontalDist - 1}); 
            if(currNode->right != nullptr) q.push({currNode->right, horizontalDist + 1}); 
            
        }
        
        for(const pair<int, int> &p : mp){
            ans.push_back(p.second); 
        }
     
        return ans; 
    }
};


// T.C. = O(n * log(hd)) + O(hd) = O(n * log(hd)) 
// S.C. = O(m) + O(hd) + O(hd) = O(max(h, hd)) 

// Here, n = the total number of nodes which are present inside the given binary tree, h = the height of the given binary tree 
// m = the maximum number of nodes which are present at any level of the given binary tree, and hd = the maximum number of unique horizontal distance values which are present inside the given binary tree 