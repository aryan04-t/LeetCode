// GeeksForGeeks (Level Order Traversal): 
// https://www.geeksforgeeks.org/problems/level-order-traversal/1 


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

// A binary tree Node

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


class Solution{
    
    public:
    
    vector<int> levelOrder(Node* root){
      
        queue<Node*> q;
        q.push(root);
        
        vector<int> levelOrderTraversal;

      
        while(!q.empty()){
            
            Node* temp = q.front();
            q.pop();
            
            levelOrderTraversal.push_back( temp->data );
            
            if(temp->left != nullptr){
                q.push( temp->left ); 
            }
            
            if(temp->right != nullptr){
                q.push( temp->right ); 
            }
            
        }
        
        return levelOrderTraversal; 
      
    }
};


// T.C. = O(n) 
// S.C. = O(m) 

// Here, n = total number of nodes which are present inside the given binary tree, and m = highest number of nodes which are present in any level of the given binary tree 