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
private:
    void invertTreeHandler(TreeNode *root) {
        if(root==NULL) return;

        swap(root->left, root->right);
        invertTreeHandler(root->left);
        invertTreeHandler(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        invertTreeHandler(root);
        return root;
    }
};
