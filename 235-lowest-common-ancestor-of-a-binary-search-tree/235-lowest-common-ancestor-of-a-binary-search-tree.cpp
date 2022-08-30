/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p, q);
    }
    
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        int r_val = root->val;
        int p_val = p->val;
        int q_val = q->val;
        
        if (r_val == p_val)
            return p;
        if (r_val == q_val)
            return q;
        
        if (r_val > p_val && r_val > q_val) {
            return findLCA(root->left, p, q);
        } else if (r_val < p_val && r_val < q_val) {
            return findLCA(root->right, p, q);
        } else { // r_val between p.val and q.val
            return root;
        }
    }
};