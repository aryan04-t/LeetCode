// GeeksForGeeks (Sum Tree): 
// https://www.geeksforgeeks.org/problems/sum-tree/1 


struct Node{ 
    int data; 
    Node* left, * right; 
}; 


// - - - - - - - - - - 


/*  
    Tree node
    struct Node{
        int data;
        Node* left, * right;
    }; 
*/


class Solution{
public:
    
    int helper(Node* root, bool &isValid){
        
        if(root == nullptr){
            return 0;
        }
        
        int leftSum = helper(root->left, isValid); 
        int rightSum = helper(root->right, isValid); 
        
        int sum = leftSum + rightSum;
        
        if(leftSum == 0 && rightSum == 0){
            return root->data; 
        }
        else if(root->data != sum){
            isValid = false;
        } 
        
        return root->data + sum; 
        
    }
    
    bool isSumTree(Node* root){
     
        bool isValid = true;
        helper(root, isValid);
        
        return isValid;
        
    }
    
};


// T.C. = O(n) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree 