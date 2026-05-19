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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        // if root is greater than p and q, then they are present on the left side of root
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
        // if root is less than p and q, then they are present on the right side of root
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
        // else root acts as the LCA
        return root;
    }
};
