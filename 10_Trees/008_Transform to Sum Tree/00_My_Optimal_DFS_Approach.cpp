// GeeksForGeeks (Transform to Sum Tree): 
// https://www.geeksforgeeks.org/problems/transform-to-sum-tree--170645/1 


struct Node{
    int data;
    Node* left, * right;
}; 


// - - - - - - - - - -  


/* 
    A binary tree node
    struct Node{
        int data;
        Node* left, * right;
    }; 
*/


class Solution {
public:

    int helper(Node* node){
        
        if(node == nullptr){
            return 0; 
        }
        
        int leftSum = helper(node->left); 
        int rightSum = helper(node->right); 
        
        int currData = node->data;
        node->data = leftSum + rightSum; 
        
        return currData + leftSum + rightSum; 
        
    }
  
    void toSumTree(Node *node){
        
        helper(node);
        
    }
};


// T.C. = O(n) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree 