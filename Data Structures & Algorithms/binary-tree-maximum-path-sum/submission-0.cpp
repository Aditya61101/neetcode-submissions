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
    int solve(TreeNode* root, int &sum) {
        if(!root) return 0;
        int leftVal = solve(root->left,sum);
        int rightVal = solve(root->right,sum);

        int currSum = root->val + max({0,leftVal,rightVal, leftVal+rightVal});
        sum = max(sum,currSum);

        return root->val + max({0,leftVal,rightVal});
    }
public:
    int maxPathSum(TreeNode* root) {
        int sum = -1e9;
        solve(root,sum);
        return sum;
    }
};
