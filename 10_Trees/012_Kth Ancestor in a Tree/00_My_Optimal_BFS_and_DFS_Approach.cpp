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


int findLevel(Node* root, int node){
    
    queue<Node*> q;
    q.push(root); 
    
    int levelSize = q.size(); 
    int nodeLevel = -1;
    
    bool isFound = false; 
    
    while(!q.empty()){
        
        nodeLevel++; 
        levelSize = q.size(); 
        
        for(int i=0; i < levelSize; i++){
            
            Node* currNode = q.front(); 
            q.pop(); 
            
            if(currNode->data == node){
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
    
    return nodeLevel; 
    
}


int helper(Node* root, int &k, int node){
    
    if(root == nullptr){
        return 0; 
    }
    
    if(root->data == node){
        return node;
    }
    
    int leftAns = helper(root->left, k, node); 
    int rightAns = helper(root->right, k, node); 
    
    if(leftAns == 0 && rightAns == 0){
        return 0; 
    }
    else if(leftAns != 0 && rightAns == 0){
        if(k > 0){
            k--;
        }
        if(k == 0){
            k = -1;
            return root->data; 
        }
        return leftAns; 
    }
    else if(leftAns == 0 && rightAns != 0){
        if(k > 0){
            k--;
        }
        if(k == 0){
            k = -1;
            return root->data; 
        }
        return rightAns; 
    }
    
}


int kthAncestor(Node *root, int k, int node){
    
    int nodeLevel = findLevel(root, node);
    if( (nodeLevel - k) < 0) return -1; 

    return helper(root, k, node); 

}


// T.C. = O(n) + O(n) = O(n)
// S.C. = O(m) + O(h) = O(m + h) 

// Here, n = the total number of nodes which are present in the given binary tree, m = the maximum number of nodes which are present at any level of the given binary tree, and h = the height of the given binary tree 