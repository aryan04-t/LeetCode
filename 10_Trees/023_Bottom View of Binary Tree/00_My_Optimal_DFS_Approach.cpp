// GeeksForGeeks (Bottom View of Binary Tree): 
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1 


#include<vector>
#include<map> 
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

    void getBottomView(Node* root, int level, int horizontalDist, map<int, pair<int, int>> &mp){
        
        if(root == nullptr) return; 
        
        map<int, pair<int, int>>::iterator it = mp.find(horizontalDist); 
        
        if(it == mp.end()){
            mp[horizontalDist] = {level, root->data}; 
        }
        else{
            if(level >= it->second.first){
                mp[horizontalDist] = {level, root->data}; 
            }
        }
        
        getBottomView(root->left, level + 1, horizontalDist - 1, mp); 
        getBottomView(root->right, level + 1, horizontalDist + 1, mp); 
        
    }
  
    vector <int> bottomView(Node *root) {

        int level = 0; 
        int horizontalDist = 0; 
        
        map<int, pair<int, int>> mp; 
        vector<int> ans; 
        
        getBottomView(root, level, horizontalDist, mp);
        
        for(const pair<int, pair<int, int>> &p : mp){
            ans.push_back(p.second.second); 
        }
        
        return ans; 
    }
};


// T.C. = O(n * (log(hd) + log(hd))) + O(hd) = O(n * log(hd)) 
// S.C. = O(h) + O(hd) + O(hd) = O(max(h, hd)) 

// Here, n = the total number of nodes which are present inside the given binary tree, h = the height of the given binary tree 
// and hd = the maximum number of unique horizontal distance values which are present inside the given binary tree 