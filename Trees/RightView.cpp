199. Binary Tree Right Side View
/* Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.*/

TC->O(N)
SC->O(N)

a)

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
    void rightView(TreeNode* root, int level, vector<int> &res)
    {
        if(root==NULL)
            return;
        if(level==res.size())
            res.push_back(root->val);
        rightView(root->right,level+1,res);
        rightView(root->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightView(root,0,res);
        return res;
        // vector<int> res;
        // if(root==NULL)
        //     return res;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty())
        // {
        //     int len=q.size();
        //     for(int i=0;i<len;i++)
        //     {
        //       TreeNode* temp=q.front();
        //       q.pop();
        //       if(i==len-1)
        //           res.push_back(temp->val);
        //       if(temp->left)
        //           q.push(temp->left);
        //       if(temp->right)
        //           q.push(temp->right);
        //     }            
        // }
        // return res;
    }
};

 b)   vector<int> rightSideView(TreeNode* root) {      
        vector<int> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
              TreeNode* temp=q.front();
              q.pop();
              if(i==len-1)
                  res.push_back(temp->val);
              if(temp->left)
                  q.push(temp->left);
              if(temp->right)
                  q.push(temp->right);
            }            
        }
        return res;
    }