145. Binary Tree Postorder Traversal
/* Given the root of a binary tree, return the postorder traversal of its nodes' values. */

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
    vector<int> postorderTraversal(TreeNode* root) {
         /* 1 Stack Method
        TC->O(N)
        SC->O(N)
        */
        
        vector<int> result;
        stack<TreeNode*> s;
        if(root==NULL)
            return result;
        s.push(root);
        TreeNode* cur,*temp;
        cur=root->left;
        while(cur!=NULL || !s.empty())
        { if(cur!=NULL)
        {
            s.push(cur);
            cur=cur->left;
        }
        else
        {
            temp=s.top()->right;            
            if(temp==NULL)
            {
                temp=s.top();
                s.pop();
                result.push_back(temp->val);
                while(!s.empty() && temp==s.top()->right)
                {
                    temp=s.top();
                    s.pop();
                    result.push_back(temp->val);
                }                
            }
            else
            cur=temp;
        }
         
        }
        return result;
        /* 2 Stacks Method
        TC->O(N)
        SC->O(2N)
        */
       //  vector<int> result;
       // if(root==NULL)
       //    return result;
       //  TreeNode* cur;
       //  stack<TreeNode*> s1,s2;
       //  s1.push(root);
       //  while(!s1.empty())
       //  {
       //      cur=s1.top();
       //      s1.pop();
       //      s2.push(cur);
       //      if(cur->left)s1.push(cur->left);
       //      if(cur->right)s1.push(cur->right);
       //  }
       //  while(!s2.empty())
       //  {
       //      result.push_back(s2.top()->val);
       //      s2.pop();
       //  }
       //  return result;
       
        /* Recursion
        TC->O(N)
        SC->O(N)
        */
        // if(root==NULL)
        //     return result;
        // result=postorderTraversal(root->left);
        // result=postorderTraversal(root-> right);
        // result.push_back(root->val);
        // return result;
    }
};