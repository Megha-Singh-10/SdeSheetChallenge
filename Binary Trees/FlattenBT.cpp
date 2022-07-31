void flatten(node* root) {
        node* cur = root;
		while (cur)
		{
			if(cur->left)
			{
				node* pre = cur->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    }
