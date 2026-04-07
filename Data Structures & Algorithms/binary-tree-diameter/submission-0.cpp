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
    int solve(TreeNode *root, int &sum) {
        if(root==NULL) return 0;

        int left=solve(root->left, sum);
        int right=solve(root->right, sum);
        sum=max(sum, left+right);
        return 1+max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int sum=0;
        solve(root, sum);
        return sum;
    }
};
