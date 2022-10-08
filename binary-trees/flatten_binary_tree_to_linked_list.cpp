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
    void flatten(TreeNode* root) {
        if(!root)   return;
        
        TreeNode*curr=root,*prev=NULL;
        
        while(curr!=NULL){
            if(curr->left!=NULL){
                prev=curr->left;
                while(prev->right)   prev=prev->right;
                
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};

//  Question Link:
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
