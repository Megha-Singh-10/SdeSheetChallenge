110. Balanced Binary Tree
/* Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1. */

TC->O(N)
SC->O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int heightBalanced(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lh=heightBalanced(root->left);
        int rh=heightBalanced(root->right);
        if(lh==-1||rh==-1)
            return -1;
        return abs(lh-rh)>1?-1:(1+max(lh,rh));
    }
    bool isBalanced(TreeNode* root) {
        int height=heightBalanced(root);
        if(height==-1)
            return false;
        else
            return true;
    }
};