/*
    Time Complexity : O(N)
    Space Complexity : O(N)

    where 'N' is the number of nodes in the BST.
*/

void inorder(BinaryTreeNode<int> *root, vector<int> &inorderArray)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, inorderArray);

    inorderArray.push_back(root->data);

    inorder(root->right, inorderArray);
}

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    // To store the inorder traversal of the BST.
    vector<int> inorderArray;

    inorder(root, inorderArray);

    int predecessor = -1, successor = -1;

    for (int i = 0; i < inorderArray.size(); i++)
    {
        if (inorderArray[i] == key)
        {
            // If predecessor exist.
            if (i - 1 >= 0)
            {
                predecessor = inorderArray[i - 1];
            }

            // If successor exist.
            if (i + 1 < inorderArray.size())
            {
                successor = inorderArray[i + 1];
            }
            break;
        }
    }

    return {predecessor, successor};
}