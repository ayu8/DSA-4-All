class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> res;
        stack <TreeNode*> stk_node;
        while (stk_node.size()!=0 || root!=NULL) {
            if (root == NULL) {
                root = stk_node.top();
                stk_node.pop();
            } 
            else 
            {
                res.push_back(root -> val);
                if (root -> right != NULL)
                  stk_node.push(root -> right);
                root = root -> left;
            }
        }
        return res;
    }
};

// question link
// https://leetcode.com/problems/binary-tree-preorder-traversal/
