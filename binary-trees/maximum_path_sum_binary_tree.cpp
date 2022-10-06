//link of the problem

// https://leetcode.com/problems/binary-tree-maximum-path-sum/
class Solution {
public:
    int findmaxpathsum(TreeNode* root, int &maxi){
        if(root==NULL)
            return 0;
        int leftmaxpath=max(0,findmaxpathsum(root->left,maxi));
        int rightmaxpath=max(0,findmaxpathsum(root->right,maxi));
        int value=root->val;
        maxi=max(maxi,leftmaxpath+rightmaxpath+value);
        return max(leftmaxpath,rightmaxpath)+value;
        
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findmaxpathsum(root,maxi);
        return maxi;
    }
};