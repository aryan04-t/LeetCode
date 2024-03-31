// GeeksForGeeks (Left View of Binary Tree): 
// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1 


#include<vector> 
#include<map> 
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


void getLeftView(Node* root, int level, map<int, int> &mp){
    
    if(root == nullptr) return; 
    
    if(mp.find(level) == mp.end()){
        mp[level] = root->data; 
    }
    
    getLeftView(root->left, level + 1, mp); 
    getLeftView(root->right, level + 1, mp); 
    
}

vector<int> leftView(Node *root){
    
    map<int, int> mp; 
    int level = 0;
    
    getLeftView(root, level, mp);
    
    vector<int> ans; 
    for(const pair<int, int> &p : mp){
        ans.push_back(p.second); 
    }
    
    return ans;
}


// T.C. = O(n * (log(n) + log(n))) = O(n * log(n)) 
// S.C. = O(h) + O(n) + O(n) = O(n) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree 