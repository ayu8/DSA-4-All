
// Link: https://leetcode.com/problems/add-one-row-to-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if(!root) return NULL;
    if(depth == 1){
        TreeNode* node = new TreeNode(val);
        node->left = root;
        return node;
    }
    int level = 1;
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty()){
        if(level == depth-1){
            int n = q.size();
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left){
                    TreeNode* leftnode = temp->left;
                    TreeNode* insert = new TreeNode(val);
                    temp->left = insert;
                    insert->left = leftnode;
                    q.push(insert);
                }else{
                    TreeNode* insert = new TreeNode(val);
                    temp->left = insert;
                    q.push(insert);
                }
                
                if(temp->right){
                    TreeNode* rightnode = temp->right;
                    TreeNode* insert = new TreeNode(val);
                    temp->right = insert;
                    insert->right = rightnode;
                    q.push(insert);
                }else{
                    TreeNode* insert = new TreeNode(val);
                    temp->right = insert;
                    q.push(insert);
                }
                
            }
            level++;
        }
        else{
            int n = q.size();
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
    }
    
    return root;
}
};
