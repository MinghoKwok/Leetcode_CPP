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
    boolean balance = true;
    public boolean isBalanced(TreeNode root) {
        dfs(root);
        return balance;
    }
    
    public int dfs(TreeNode root) {
        if (root == null)   return 0;
        
        int left = dfs(root.left);
        int right = dfs(root.right);
        
        if (left - right < -1 || left - right > 1) {
            balance = false;
        }
        
        return Math.max(left + 1, right + 1);
    }
}