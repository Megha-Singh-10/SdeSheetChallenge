144. Binary Tree Preorder Traversal
/* Given the root of a binary tree, return the preorder traversal of its nodes' values. */

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
    
    // vector<int> result;
    vector<int> preorderTraversal(TreeNode* root) { 
          /* Stack
    TC->O(N)
    SC->O(N)
    */
        vector<int> result;
        stack<TreeNode*> s;
        if(root==NULL)
            return result;
        TreeNode* cur=root;
        s.push(cur);
        while(!s.empty())
        {   
            cur=s.top();
            s.pop();
            result.push_back(cur->val);
            if(cur->right)
            { s.push(cur->right);              
            }
            if(cur->left)
            {s.push(cur->left);             
            }
            
        }
        return result;
        /* Recursive
    TC->O(N)
    SC->O(N)
    */
      // if(root==NULL)
      //     return result;
      // result.push_back(root->val);
      // result=preorderTraversal(root->left);
      // result=preorderTraversal(root->right);
      // return result;
    }
};