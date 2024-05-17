// LeetCode (988. Smallest String Starting From Leaf): 
// https://leetcode.com/problems/smallest-string-starting-from-leaf/ 


#include<string> 
#include<algorithm> 
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

    void dfs(TreeNode* root, string &curr, string &smallest){

        if(root == nullptr) return; 

        curr.push_back(char(root->val + 'a')); 

        if(root->left == nullptr && root->right == nullptr){
            reverse(curr.begin(), curr.end()); 
            if(smallest == "") smallest = curr; 
            else{
                if(curr < smallest) smallest = curr; 
            }
            reverse(curr.begin(), curr.end()); 
        }

        dfs(root->left, curr, smallest); 
        dfs(root->right, curr, smallest); 

        curr.pop_back(); 
    }

    string smallestFromLeaf(TreeNode* root) {

        string curr; 
        string smallest = ""; 

        dfs(root, curr, smallest); 

        return smallest; 
    }
};


// T.C. = O(((n+1)/2) - 1) * O(1)) + O(((n+1)/2) * O(m/2 + m/2)) = O(n) + O(n*m) = O(n*h) 
// S.C. = O(h) + O(h) + O(h) = (s.c. caused by the function call stack) + (s.c. caused by the "curr" string) + (s.c. caused by the "ans" string) = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree, 
// h = the height of the given binary tree, 
// and m = to the average length of all the root to leaf node strings, and in worst case m == h 