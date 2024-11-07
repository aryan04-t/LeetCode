// LeetCode (103. Binary Tree Zigzag Level Order Traversal): 
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/ 


#include<vector> 
#include<queue> 
#include<stack> 
using namespace std; 


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// - - - - - - - - - - 


/*
    Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
*/


class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root == nullptr) return {}; 

        queue<TreeNode*> q1; 
        queue<TreeNode*> q2; 
        q1.push(root); 

        int levelSize = 1;  
        vector<vector<int>> ans; 

        while(!q1.empty() || !q2.empty()){
            
            vector<int> currLevel; 

            if(!q1.empty()){

                levelSize = q1.size();

                for(int i=0; i < levelSize; i++){

                    TreeNode* currNode = q1.front(); 
                    q1.pop(); 

                    currLevel.push_back(currNode->val); 

                    if(currNode->left != nullptr) q2.push(currNode->left); 
                    if(currNode->right != nullptr) q2.push(currNode->right); 

                }
            }
            else{

                levelSize = q2.size(); 
                stack<int> st;

                for(int i=0; i < levelSize; i++){

                    TreeNode* currNode = q2.front(); 
                    q2.pop(); 

                    st.push(currNode->val); 

                    if(currNode->left != nullptr) q1.push(currNode->left);
                    if(currNode->right != nullptr) q1.push(currNode->right);

                }

                while(!st.empty()){
                    currLevel.push_back(st.top()); 
                    st.pop(); 
                }
            }

            ans.push_back(currLevel); 

        }

        return ans; 

    }
}; 


// T.C. = O(ne) + O(2*no) = O(n) 
// S.C. = O(n) + O(m) + O(k) = (this s.c. is caused due to 2-D vector named "ans") + (this s.c. is caused due to the 2 queues that I used) + (this s.c. is caused by the stack) = O(n) 

// Here, ne = the total number of nodes which are present at all even levels, and no = the total number of nodes which are present at all odd levels 
// n = the total number of nodes which are present in the given binary tree, m = the maximum number of nodes which are present at any level of the given binary tree, and k = the maximum number of nodes which are present at any odd level of the given binary tree, and here 1st level of the binary tree is referred as 0th level of the tree 