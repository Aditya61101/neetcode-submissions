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
    bool solve(TreeNode* root, int low, int high) {
        // whole path was successfully traversed
        if(!root) return true;
        
        // out of bound values: current node's value must be between the bound (low,high)
        if(root->val <=low || root->val >=high) return false;
        
        // going to left hence, bound becomes (low, root->val)
        // going to right hence, bound becomes (root->val, high)
        return solve(root->left, low, root->val) && solve(root->right, root->val, high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, INT_MIN, INT_MAX);
    }
};
