// GeeksForGeeks (Left View of Binary Tree): 
// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1 


#include<vector> 
using namespace std; 


struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


// - - - - - - - - - - 


/* 

A binary tree node

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

*/


int getHeight(Node* root){
    
    if(root == nullptr) return 0;
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right); 
    
    return max(leftHeight, rightHeight) + 1;
    
}


void getLeftView(Node* root, int height, bool &done, vector<bool> &isPrinted, vector<int> &ans){
 
    if(root == nullptr) return; 
    
    if(done) return; 
    
    if(!isPrinted[height]){
        ans.push_back(root->data); 
        isPrinted[height] = true; 
    }
    
    getLeftView(root->left, height - 1, done, isPrinted, ans); 
    getLeftView(root->right, height - 1, done, isPrinted, ans); 
    
    if(height == 1) done = true; 
}


vector<int> leftView(Node *root){
    
    int height = getHeight(root);
    
    vector<bool> isPrinted(height+1, false); 
    vector<int> ans; 
    
    bool done = false; 
    
    getLeftView(root, height, done, isPrinted, ans); 
    
    return ans;
}


// T.C. = O(n) + O(n) = O(n) 
// S.C. = O(h) + O(h+1) + O(h) + O(n) = O(n) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree