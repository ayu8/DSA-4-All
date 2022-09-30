void inOrder(Node *root, int &k, int &val)
{
    if (!root)
        return;
    if (k < 0)
        return;

    inOrder(root->left, k, val);
    k--;
    if (k == 0)
    {
        val = root->data;
        return;
    }
    inOrder(root->right, k, val);
}


// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int k)
{
    // add code here.
    int val = -1;
    inOrder(root, k, val);

    return val;
}