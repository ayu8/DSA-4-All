/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    String ans="";
    void helper(TreeNode root, String str) {
        if(root==null)
            return;
        str=(char)(root.val+97)+str;
        if(root.left==null && root.right==null) {
            if(ans=="" || ans.compareTo(str)>0)
                ans=str;
        }
        helper(root.left, str);
        helper(root.right, str);
    }
    public String smallestFromLeaf(TreeNode root) {
        helper(root, "");
        return ans;
    }
}



// Leetcode link :- https://leetcode.com/problems/smallest-string-starting-from-leaf/
