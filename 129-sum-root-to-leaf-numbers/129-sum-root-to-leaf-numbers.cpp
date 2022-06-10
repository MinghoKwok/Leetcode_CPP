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
    int sumNumbers(TreeNode* root) {
        return rtnSum(root, 0);
    }
    
    int rtnSum(TreeNode* root, int val) {    
        if (root->left == NULL && root->right == NULL) {
            return val * 10 + root->val;
        } else {
            int sum = 0;
            if (root->left != NULL)
                sum += rtnSum(root->left, val * 10 + root->val);
            if (root->right != NULL)
                sum += rtnSum(root->right, val * 10 + root->val);
            
            return sum;
        }
    }
};