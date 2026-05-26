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
    int solve(TreeNode* root, int &k) {
        if(!root) return 0;
        // cout<<root->val<<" "<<k<<"\n";
        int left = solve(root->left,k);
        k-=1; if(k==0) return root->val;
        int right = solve(root->right,k);
        // cout<<"---------\n";
        // cout<<root->val<<" "<<k<<"\n";
        return left | right;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return solve(root,k);
    }
};
