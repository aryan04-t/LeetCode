// GeeksForGeeks (Kth Ancestor in a Tree): 
// https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1 


#include<vector> 
using namespace std; 


struct Node{
    int data;
    struct Node *left, *right;
};


// - - - - - - - - - - 


/*
    Structure of the node of the binary tree is as
    struct Node{
        int data;
        struct Node *left, *right;
    };
*/


void findPath(Node* root, int target, vector<int> &path, bool &isFound){
    
    if(root == nullptr) return; 
    if(isFound) return; 
    
    if(!isFound) path.push_back(root->data); 
    
    if(root->data == target) isFound = true; 
    
    findPath(root->left, target, path, isFound); 
    findPath(root->right, target, path, isFound); 
    
    if(!isFound) path.pop_back(); 
    
}


int kthAncestor(Node *root, int k, int node){
    
    vector<int> nodePath; 
    bool isFound = false; 
    
    findPath(root, node, nodePath, isFound); 

    while(!nodePath.empty() && k != 0){
        nodePath.pop_back(); 
        k--; 
    }

    if(nodePath.empty()) return -1; 
    else return nodePath.back(); 

}


// T.C. = O(n) + O(h) = O(n) 
// S.C. = O(h) + O(h) = O(h) 

// Here, n = the total number of nodes which are present in the given binary tree, and h = the height of the given binary tree 
