101. Symmetric Tree
/* Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).*/

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
    bool isSymmetricTree(TreeNode* p,TreeNode* q)
    {
        if(p==NULL || q==NULL)
            return p==q;
        if(p->val==q->val && isSymmetricTree(p->right,q->left) && isSymmetricTree(p->left,q->right))
            return true;
        else
            return false;
            
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;        
        return isSymmetricTree(root->left,root->right);
    }
};