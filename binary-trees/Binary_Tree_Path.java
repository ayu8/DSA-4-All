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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> list=new ArrayList<>();
        helper(root, list, "");
        return list;
    }
    void helper(TreeNode root, List<String> list, String str) {
        if(root == null)
            return;
        if(root.left==null && root.right==null) {
            list.add(str+Integer.toString(root.val));
            return;
        }
        str+=Integer.toString(root.val)+"->";
        helper(root.left, list, str);
        helper(root.right, list, str);
    }
}



//Leetcode link :- https://leetcode.com/problems/path-sum/
