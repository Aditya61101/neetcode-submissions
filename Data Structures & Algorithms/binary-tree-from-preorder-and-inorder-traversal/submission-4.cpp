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
    int inIdx=0, preIdx=0;
    TreeNode* solve(vector<int>& preorder, vector<int>&inorder, int limit) {
        if(preIdx>=preorder.size()) return nullptr;
        // left subtree completed
        if(inorder[inIdx]==limit) {
            inIdx+=1; return nullptr;
        }
        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);
        root->left = solve(preorder,inorder,val);
        root->right = solve(preorder,inorder,limit);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return solve(preorder,inorder,INT_MAX);
    }
};
