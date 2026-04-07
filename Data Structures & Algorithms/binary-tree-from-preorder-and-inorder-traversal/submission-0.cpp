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
    int idx=-1;
    TreeNode* solve(int l, int r, vector<int>&preorder, unordered_map<int, int>&mp) {
        if(idx>(int)preorder.size() || l>r) return nullptr;
        idx++;
        int nodeVal = preorder[idx];
        int j = mp[nodeVal];
        TreeNode *node = new TreeNode(nodeVal);
        node->left = solve(l, j-1, preorder, mp);
        node->right = solve(j+1, r, preorder, mp);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mp;
        int n = preorder.size();
        for(int i=0;i<n;i++) {
            mp[inorder[i]]=i;
        }
        return solve(0, n-1, preorder, mp);
    }
};
