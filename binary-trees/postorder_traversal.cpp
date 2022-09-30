class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> res;
        if(root == NULL)
		        return res;
        stack <TreeNode*> stk_node;
        stk_node.push(root);
        while (stk_node.size()!=0) {
            TreeNode* temp = stk_node.top();
            res.push_back(temp -> val);
            stk_node.pop();
            if(temp -> left)
                stk_node.push(temp -> left);
            if(temp -> right)
                stk_node.push(temp -> right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// question link
// https://leetcode.com/problems/binary-tree-postorder-traversal
