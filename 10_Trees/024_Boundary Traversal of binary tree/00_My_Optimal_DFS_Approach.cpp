// GeeksForGeeks (Boundary Traversal of binary tree): 
// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1 


#include<vector> 
using namespace std; 


struct Node{
    int data;
    Node* left, * right;
}; 


// - - - - - - - - - - 


/* 

A binary tree Node
struct Node{
    int data;
    Node* left, * right;
}; 

*/


class Solution {
public:

    void getLeftBoundary(Node* root, vector<int> &ans, bool &done){
        
        if(root == nullptr) return; 
        
        if(done) return; 
        
        if(root->left == nullptr && root->right == nullptr){
            done = true; 
            return;
        }
        
        ans.push_back(root->data); 
        
        getLeftBoundary(root->left, ans, done); 
        getLeftBoundary(root->right, ans, done); 
    }
    
    void getLeafNodes(Node* root, vector<int> &ans){
        
        if(root == nullptr) return; 
        
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(root->data); 
            return; 
        }
        
        getLeafNodes(root->left, ans);
        getLeafNodes(root->right, ans);
    }
    
    void getRightBoundary(Node* root, vector<int> &ans, bool &done){
        
        if(root == nullptr) return; 
        
        if(done) return; 
        
        if(root->left == nullptr && root->right == nullptr){
            done = true;
            return; 
        } 
        
        getRightBoundary(root->right, ans, done); 
        getRightBoundary(root->left, ans, done); 
        
        ans.push_back(root->data); 
    }

    vector<int> boundary(Node *root){
        
        vector<int> ans; 
        ans.push_back(root->data); 
        
        if(root->left == nullptr && root->right == nullptr){
            return ans; 
        }
        
        bool done = false; 
        getLeftBoundary(root->left, ans, done); 
        
        getLeafNodes(root, ans); 
        
        done = false; 
        getRightBoundary(root->right, ans, done); 
        
        return ans; 
    }
};


// T.C. = O(h) + O(n) + O(h) = O(n) 
// S.C. = O(h) + O(n) = (this s.c. is caused due to the function callstack) + (s.c. caused by the "ans" vector) = O(n) 

// Here, n = the total number of nodes which are present in the given binary tree, and h = the height of the given binary tree 