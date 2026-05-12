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
    int findHeight(TreeNode* root) {
        if(!root) return 0;
        return 1+max(findHeight(root->left), findHeight(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        
        int currDiameter = leftHeight+rightHeight;
        int leftSubtreeDiameter = diameterOfBinaryTree(root->left);
        int rightSubtreeDiameter = diameterOfBinaryTree(root->right);
        // for current root, its maximum diameter is
        // diameter through root
        // leftsubtree diameter
        // rightsubtree diameter
        return max({currDiameter, leftSubtreeDiameter, rightSubtreeDiameter});
    }
};
