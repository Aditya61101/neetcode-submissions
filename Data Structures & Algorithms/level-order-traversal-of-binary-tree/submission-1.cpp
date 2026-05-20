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
    void solve(TreeNode* root, int level, vector<vector<int>>&ans) {
        if(!root) return;
        if(ans.size() < level+1) ans.resize(level+1);
        ans[level].push_back(root->val);
        solve(root->left,level+1,ans);
        solve(root->right,level+1,ans);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        solve(root,0,ans);
        return ans;
    }
};
