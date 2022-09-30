vector<int> levelOrder(Node *node)
{
    // Your code here

    vector<int> res;
    if (node == NULL)
        return res;

    queue<Node *> q;

    q.push(node);

    while (!q.empty())
    {
        Node *current = q.front();
        res.push_back(current->data);

        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
        q.pop();
    }

    return res;
}