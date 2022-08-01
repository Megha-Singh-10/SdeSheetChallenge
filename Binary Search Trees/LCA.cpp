/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where N is the total number of nodes of the BST.
*/


int findLCA(TreeNode<int>* currNode, TreeNode<int>* P, 
            TreeNode<int>* Q, TreeNode<int>* &LCA)
{
    if (currNode == NULL)
    {
        return 0;
    }

    int isTrueLeft = findLCA(currNode -> left, P, Q, LCA);
    int isTrueRight = findLCA(currNode -> right, P, Q, LCA);
    int isTrue = 0;

    if (currNode -> data == P -> data)
    {
        isTrue++;
    }

    if (currNode -> data == Q -> data)
    {
        isTrue++;
    }

    // Current Node is the LCA
    if (isTrueLeft + isTrueRight + isTrue >= 2)
    {
        LCA = currNode;
    }

    if (isTrueLeft + isTrueRight + isTrue)
    {
        return 1;
    }
    
    return 0;
}


TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    TreeNode<int>* LCA;

    findLCA(root, P, Q, LCA);

    return LCA;
}