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
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        bool isEqual = root==p || root==q;
        if(!isEqual && !left && !right) return nullptr;
        // if root is equal to p or q or root's left and right returns a node
        if(isEqual || (left && right)) return root;
        // root was neither LCA nor was equal to any p or q but one of its right child
        // was equal to p or q
        if(!left && right) return right;
        // root was neither LCA nor was equal to any p or q but one of its left child
        // was equal to p or q
        return left;
    }
};
