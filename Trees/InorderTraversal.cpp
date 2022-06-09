94. Binary Tree Inorder Traversal
/* Given the root of a binary tree, return the inorder traversal of its nodes' values. 
*/

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
    // vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        //Stack
        // TC->O(N) 
        //SC->O(N)
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(cur!=NULL || !s.empty())
        {
           if(cur!=NULL)
           {
               s.push(cur);
               cur=cur->left;
           }
            else
            {
                if(!s.empty())
                {
                cur=s.top();
                s.pop();
                res.push_back(cur->val);
                cur=cur->right;
                }
            }
        }        
        return res;
       //Recursion
       //TC->O(N)
       //SC->O(N)
       // if(root==NULL)
       //     return res;
       // res=inorderTraversal(root->left);       
       // res.push_back(root->val);
       // res=inorderTraversal(root->right);
       // return res;
    }
};