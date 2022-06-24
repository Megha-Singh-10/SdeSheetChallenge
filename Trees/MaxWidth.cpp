662. Maximum Width of Binary Tree
/* Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.*/

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
 
    int widthOfBinaryTree(TreeNode* root) {
          int maxWidth=0;
          if(root==NULL)
              return 0;
          queue<pair<TreeNode*,int>> q;
          q.push({root,0});
          while(!q.empty())
          {
              int len=q.size();
              int first,last;
              pair<TreeNode*,int> temp;
              for(int i=0;i<len;i++)
              {                  
                  temp=q.front();                 
                  q.pop();
                  if(i==0)
                  {
                      first=temp.second;
                  }
                  if(i==len-1)
                  {
                      last=temp.second;
                      maxWidth=max(maxWidth,last-first+1);                      
                  }
                  if(temp.first->left)
                  {
                      q.push({temp.first->left,(long long)2*(temp.second-first)+1});                      
                  } 
                  if(temp.first->right)
                  {
                      q.push({temp.first->right,(long long)2*(temp.second-first)+2});
                  }
              }            
          }
          return maxWidth;
    }

//Way 2 with same complexity

//     int widthOfBinaryTree(TreeNode* root) {
//         if(root == NULL)
//             return 0;
        
//         int res = 1;
//         queue<pair<TreeNode*, int>> q;
        
//         // I am using intialising list
//         q.push({root, 0});      // also can use make_pair
        
//         while(!q.empty())
//         {
//             int cnt = q.size();
//             // start is the index of root node for first level
//             int start = q.front().second;
//             int end = q.back().second;
            
//             res = max(res,end-start + 1);
            
//             for(int i = 0; i <cnt; ++i)
//             {
//                 pair<TreeNode*, int> p = q.front();
//                 // we will use it while inserting it children
//                 // left child will be 2 * idx + 1;
//                 // right chils will be 2 * idx + 2;
//                 int idx = p.second - start;
                
//                 q.pop();
                
//                 // if  left child exist
//                 if(p.first->left != NULL)
//                     q.push({p.first->left, (long long)2 * idx + 1});
                
//                 // if right child exist
//                 if(p.first->right != NULL)
//                     q.push({p.first->right, (long long) 2 * idx + 2});
//             }
//         }
        
//         return res;
        
//     }
};

