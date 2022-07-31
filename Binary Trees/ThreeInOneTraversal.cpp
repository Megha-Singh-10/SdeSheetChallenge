(Coding Ninja) Pre,Post, In order traversals in one 
/* You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to find the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.*/

TC-> O(3N)
SC->O(3N)

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    std::vector<std::vector<int>> res;
    if(root==NULL)
        return res;
    std::stack<std::pair<BinaryTreeNode*,int>> s;
    s.push({root,0});
    vector<int> pre,post,inorder;
    while(!s.empty())
    {
        BinaryTreeNode* temp=s.top().first;
        int count=s.top().second;
        s.pop();
        if(count==0)
        {
            pre.push_back(temp->val);            
            s.push({temp,1});
            if(temp->left)
               s.push({temp->left,0});
        }
        else if(count==1)
        {
            inorder.push_back(temp->val);
            s.push({temp,2});
            if(temp->right)
                s.push({temp->right,0});
        }
        else
        {
            post.push_back(temp->val);
        }           
    }
    res.push_back(inorder);
    res.push_back(pre);
    res.push_back(post);
    return res;
}