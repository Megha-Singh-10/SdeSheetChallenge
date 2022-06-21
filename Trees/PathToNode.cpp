(Interview Bit) Path to Given Node
/* Problem Description

Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists. */

TC->O(N)
SC->O(N)

bool path(TreeNode* a,int b,vector<int> &res)
{
    if(a==NULL)
       return false;
    res.push_back(a->val);
    if(a->val==b)
      return true;    
    if(path(a->left,b,res) || path(a->right,b,res))
      return true;  
    res.pop_back();
      return false;  
}
vector<int> Solution::solve(TreeNode* a, int b) {
    vector<int> res;
    bool result=path(a,b,res);
    return res;
}