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
    bool balance = true;
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        
        int left_H = height(root->left);
        int right_H = height(root->right);
        
        if (abs(left_H - right_H) > 1)
            balance = false;
        
        return balance;
    }
    
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int left_H = height(root->left);
        int right_H = height(root->right);
        
        if (abs(left_H - right_H) > 1)
            balance = false;
        
        return 1 + max(left_H, right_H);
    }
    
};