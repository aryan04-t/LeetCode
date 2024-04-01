// GeeksForGeeks (Left View of Binary Tree): 
// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1 


#include<vector> 
#include<queue> 
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


vector<int> leftView(Node *root){
    
    if(root == nullptr) return {}; 
    
    vector<int> ans; 
    
    queue<Node*> q;
    q.push(root);
    
    int levelSize = 1; 
    
    while(!q.empty()){
        
        levelSize = q.size(); 
        
        for(int i=0; i < levelSize; i++){
            
            Node* currNode = q.front(); 
            q.pop(); 
            
            if(i == 0) ans.push_back(currNode->data); 
            
            if(currNode->left != nullptr) q.push(currNode->left);
            if(currNode->right != nullptr) q.push(currNode->right);
            
        }
    }
    
    return ans;
}


// T.C. = O(n) 
// S.C. = O(m) + O(n) = O(n) 

// Here, n = the total number of nodes which are present inside the given binary tree, and m = the maximum number of nodes which are present at any level of the given binary tree 