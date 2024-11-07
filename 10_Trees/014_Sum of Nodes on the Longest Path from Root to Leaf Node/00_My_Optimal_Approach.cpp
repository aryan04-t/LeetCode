// GeeksForGeeks (Sum of Nodes on the Longest Path from Root to Leaf Node): 
// https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1 


#include<cstdlib>
#include<algorithm> 
using namespace std; 


struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

// - - - - - - - - - - 


/*
    structure of the node of the binary tree is as
    struct Node{
        int data;
        struct Node *left;
        struct Node *right;
    
        Node(int x){
            data = x;
            left = NULL;
            right = NULL;
        }
    };
*/


class Solution{
public:
    
    int getHeight(Node* root){
        
        if(root == nullptr) return 0;
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        return max(leftHeight, rightHeight) + 1;
        
    }
    
    
    void helper(Node* root, int height, int currSum, int &maxSum){
        
        if(root == nullptr) return; 
        
        currSum += root->data; 
        
        if(height == 1){
            maxSum = max(maxSum, currSum); 
        }
        
        helper(root->left, height-1, currSum, maxSum); 
        helper(root->right, height-1, currSum, maxSum); 
        
    }
    
    int sumOfLongRootToLeafPath(Node *root){
        
        int height = getHeight(root);
        
        int currSum = 0;
        int maxSum = 0; 
        
        helper(root, height, currSum, maxSum); 
        
        return maxSum;
        
    }
};


// T.C. = O(n) + O(n) = O(n) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present in the given binary tree, and h = the height of the given binary tree 
