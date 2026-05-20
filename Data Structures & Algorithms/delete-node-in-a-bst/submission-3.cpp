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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // if root->val == val, take its left and attach to leftmost of right
        // link its parent with root's right child, so if root was at the left of it's parent
        // it's right child would now be the left child of root's parent.
        if(!root) return nullptr;
        
        TreeNode* parent = nullptr, *curr=root;
        // find the node to be deleted
        while(curr && curr->val!=key) {
            parent = curr;
            if(curr->val > key) curr = curr->left;
            else curr = curr->right;
        }

        // if we didnt find the key
        if(!curr) return root;
        
        TreeNode* replacement;
        
        if(!curr->right) {
            replacement = curr->left;
        } else {
            replacement = curr->right;
            TreeNode* leftMost = curr->right;
            while(leftMost->left) {
                leftMost = leftMost->left;
            }
            leftMost->left = curr->left;
        }
        
        // if no parent i.e deleted node was the root node
        if(!parent) return replacement;

        // attaching replacement with the parent
        if(parent->left==curr) parent->left=replacement;
        else parent->right=replacement;

        return root;
    }
};