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
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        if ( root == null )
            return ans;
        List<Integer> list = new ArrayList<>();
        helper( root, targetSum, list );
        return ans;
    }
    void helper( TreeNode root, int sum, List<Integer> list ) {
        if ( root == null )
            return;
        sum -= root.val;
        
        if ( root.left == null && root.right == null && sum == 0 ) {
            list.add(root.val);
            ans.add(new ArrayList<>(list));
            list.remove(list.size()-1);
            return;
        }
        if ( root.left == null && root.right == null && sum != 0 )
            return;
        
        list.add(root.val);

        helper(root.left, sum, list);
        helper(root.right, sum, list);
        list.remove(list.size()-1);
        
    } 
}




// Leetcode link :- https://leetcode.com/problems/path-sum-ii/
