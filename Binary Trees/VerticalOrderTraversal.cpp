987. Vertical Order Traversal of a Binary Tree
/* Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree. */

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
 SC->O(N)
 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        map<int, map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;        
        q.push({root,{0,0}});
        while(!q.empty())
        {
            // int len=q.size();
            // for(int i=0;i<len;i++)
            // {
                TreeNode* temp=q.front().first;
                int x=q.front().second.first;
                int y=q.front().second.second;
                q.pop();
                
                m[x][y].insert(temp->val);
                if(temp->left)
                    q.push({temp->left,{x-1,y+1}});
                if(temp->right)
                    q.push({temp->right,{x+1,y+1}});                
                
            // }
        }
        for(auto i:m)
        {
            vector<int> row;
            for(auto j:i.second)
            {                   
                // row.insert(row.end(),j.second.begin(),j.second.end());   
                for(auto k:j.second)
                {
                    row.push_back(k);
                }
            }
            result.push_back(row);
        }
        return result;
    }
};