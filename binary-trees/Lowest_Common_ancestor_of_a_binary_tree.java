// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return ancestorHelper( root,  p, q);
    }
    
    
    TreeNode ancestorHelper(TreeNode root, TreeNode p, TreeNode q){
        if(root == null || root==p || root == q) return root;
         
        TreeNode leftFound = ancestorHelper(root.left, p, q);
        TreeNode rightFound = ancestorHelper(root.right, p, q);
        
       if(rightFound != null && leftFound != null)
            return root;
        if(leftFound != null)
        return leftFound;
         if(rightFound != null)
        return rightFound;   
        return null;
    }   
}
