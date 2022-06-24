(Coding Ninja) Children Sum Property
/* Problem Statement
Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property.
A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node is equal to the sum of the value(s) of all of its children nodes( left child and the right child).
Note :
 1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
 2. You can not change the structure of the original binary tree.
 3. A binary tree is a tree in which each node has at most two children.      
 4. You can assume the value can be 0 for a NULL node and there can also be an empty tree.*/

a) TC->O(N^2)
   SC->O(N)

/*
    Time complexity : O(N^2)
    Space complexity : O(N)

    Where 'N' is the number of nodes.
*/

// Change child values.
void increment(BinaryTreeNode < int > * root, int diff) {
    if (root -> right != NULL) {
        root -> right -> data += diff;
        increment(root -> right, diff);
    } 
    else if (root -> left != NULL) {
        root -> left -> data += diff;
        increment(root -> left, diff);
    }

}

void change(BinaryTreeNode < int > * root) {

    // Base case.
    if (root == NULL || (root -> left == NULL && root -> right == NULL)) {
        return;
    }

    // Traverse substrees.
    change(root -> left);
    change(root -> right);

    // Child sum.
    int childVal = 0;
    if (root -> left != NULL) {
        childVal += root -> left -> data;
    }

    if (root -> right != NULL) {
        childVal += root -> right -> data;
    }

    int diff = childVal - root -> data;

    // childVal > parentVal
    if (diff > 0) {
        root -> data += diff;
    } 

    else {
        increment(root, -diff);
    }

}

void changeTree(BinaryTreeNode < int > * root) {
    change(root);
}


b) TC->O(N)
SC->O(N)

/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root==NULL)
        return;
    int l=0;
    if(root->left)
        l=root->left->data;
    int r=0;
    if(root->right)
        r=root->right->data;
    int cur=root->data;
    if(cur<l+r)
    {
        cur=l+r;
        root->data=cur;
    }
    else if(cur>l+r)
    {
        if(root->left)
        root->left->data=cur;
        if(root->right)
        root->right->data=cur;
    }
//     if(root->left->data!=-1)
    changeTree(root->left);
//     if(root->right->data!=-1)
    changeTree(root->right);
    l=0;
    if(root->left)
        l=root->left->data;
    r=0;
    if(root->right)
        r=root->right->data;
    
  
      if(root->left || root->right)
         root->data=l+r;
    
}  


