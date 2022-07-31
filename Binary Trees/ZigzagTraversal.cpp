103. Binary Tree Zigzag Level Order Traversal
/* Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between). */

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

TC-> O(N)
SC-> O(N)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty())
        {
            int len=q.size();
            vector<int> row(len);
            for(int i=0;i<len;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                int index=leftToRight?i:len-1-i;                
                row[index]=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            leftToRight=!leftToRight;
            res.push_back(row);
        }
        return res;
        
    }
};