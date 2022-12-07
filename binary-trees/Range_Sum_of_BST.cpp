// Leetcode
// Link: https://leetcode.com/problems/range-sum-of-bst/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)
        {
            return 0;
        }
        int ans=0;
        if(root->val>=low && root->val<=high)
        {
            ans+=root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
            return ans;
        }
        else if(root->val>high)
        {
            return rangeSumBST(root->left,low,high);
        }
        else
        {
            return rangeSumBST(root->right,low,high);
        }
        return ans;
    }
};
