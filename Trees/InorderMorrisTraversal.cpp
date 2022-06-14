94. Binary Tree Inorder Traversal
/* Given the root of a binary tree, return the inorder traversal of its nodes' values.*/

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
     vector<int> inorderTraversal(TreeNode* root) {
       //Morris
         /* TC-> O(N)
         SC->O(1)*/
         
        vector<int> res;
        if(root==NULL)
            return res;
        TreeNode* cur=root;        
        while(cur!=NULL)
        {
            if(cur->left){
            TreeNode* temp=cur->left;            
            while(temp->right!=NULL && temp->right!=cur)
            {
                temp=temp->right;
            }
            if(temp->right!=cur)
            {
               
                temp->right=cur;
                cur=cur->left;                
            }
            else
            {
              temp->right=NULL;
              res.push_back(cur->val);
              cur=cur->right;
            }
            }
            else
            {
                res.push_back(cur->val);
              cur=cur->right;
            }
        } 
         return res;
    }
};