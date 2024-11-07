// GeeksForGeeks (Kth Ancestor in a Tree): 
// https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1 


#include<queue> 
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


int findLevel(Node* root, int target){
    
    queue<Node*> q; 
    q.push(root); 
    
    int level = -1;
    int levelSize = 1;
    bool isFound = false; 
    
    while(!q.empty()){
        
        level++; 
        levelSize = q.size();
        
        for(int i=0; i < levelSize; i++){
            
            Node* currNode = q.front(); 
            q.pop();
            
            if(currNode->data == target){
                isFound = true;
                break;
            }
            
            if(currNode->left != nullptr) q.push(currNode->left); 
            if(currNode->right != nullptr) q.push(currNode->right); 
            
        }
        
        if(isFound){
            break;
        }
    }
    
    return level; 
    
}


bool findKthAncestor(Node* root, int &k, int node, int &ans){
    
    if(root == nullptr) return false; 
    if(root->data == node) return true; 
    
    int leftAns = findKthAncestor(root->left, k, node, ans); 
    int rightAns = findKthAncestor(root->right, k, node, ans); 
    
    if(leftAns == false && rightAns == false){
        return false; 
    }
    else if(leftAns == true && rightAns == false){
        if(k > 0){
            k--; 
        }
        if(k == 0){
            k = -1; 
            ans = root->data; 
        }
        return leftAns; 
    }
    else if(leftAns == false && rightAns == true){
        if(k > 0){
            k--; 
        }
        if(k == 0){
            k = -1; 
            ans = root->data; 
        }
        return rightAns; 
    }
    
}


int kthAncestor(Node *root, int k, int node){
    
    int nodeLevel = findLevel(root, node); 
    
    if( (nodeLevel - k) < 0 ){
        return -1; 
    }
    
    int ans = 0;
    
    findKthAncestor(root, k, node, ans); 
    
    return ans; 
    
}


// T.C. = O(n) + O(n) = O(n) 
// S.C. = O(m) + O(h) = O(m + h) 

// Here, n = the total number of nodes which are present inside the given binary tree, m = the maximum number of nodes which are present at any level of the given binary tree, and h = the height of the given binary tree 
