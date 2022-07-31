124. Binary Tree Maximum Path Sum
/* A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.*/

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
    int pathSum(TreeNode* root, int &maxPath)        
    {
        if(root==NULL)
            return 0;
        int lp=max(0,pathSum(root->left,maxPath));
        int rp=max(0,pathSum(root->right,maxPath));
        maxPath=max(maxPath,root->val+lp+rp);
        return root->val+max(lp,rp);
    }
    int maxPathSum(TreeNode* root) {
        int maxPath=INT_MIN;
        int path=pathSum(root,maxPath);
        return maxPath;
    }
};