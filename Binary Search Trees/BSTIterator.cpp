/*
	Time Complexity: O(N)
	Space complexity: O(N)

	Where 'N' is the number of nodes.

*/

class BSTiterator
{
public:
	
	// Create a list to store node's value in sorted order
	vector<int> nodeValues;
	
	// This will be used to iterate over the list
	int index;

	BSTiterator(TreeNode<int> *root)
	{
		index = 0;
		inorder(root);
	}

	int next()
	{
		int nextSmallest = nodeValues[index];
	
		// Increment the index for next smallest element
		++index;
		return nextSmallest;
	}

	bool hasNext()
	{
	
		// If index is less than size of the list that means there are still some nodes left for processing
		if (index < nodeValues.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// This function will used to perform inorder traversal on the BST
	void inorder(TreeNode<int> *root)
	{
		if (root == NULL)
		{
			return;
		}
	
		// Traverse on the left child
		inorder(root->left);
	
		// Store the data
		nodeValues.push_back(root->data);
	
		// Traverse on the right child
		inorder(root->right);
	}
};