/*
    Time Complexity - O(N^2)
    Space Complexity - O(N)

    where 'N' is the number of nodes in the tree.
*/

/*************************************************************
 
        Following is the Binary Tree node structure

        class BinaryTreeNode 
        {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }
        };

*************************************************************/

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {

    // Base case.
    if(root == NULL)
    {
        return root;
    }

    if(root->left != NULL)
    {
        BinaryTreeNode<int>* left = BTtoDLL(root->left);

        // Inorder predecessor.
        while(left->right != NULL)
        {
            left = left->right;
        }

        left->right = root;
        root->left = left;
    }

    if(root->right != NULL)
    {
        BinaryTreeNode<int>* right = BTtoDLL(root->right);

        // Inorder successor.
        while(right->left != NULL)
        {
            right = right->left;
        }

        right->left = root;
        root->right = right;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}