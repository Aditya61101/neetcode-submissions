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
    TreeNode* solve(vector<int>& preorder, int l, int r, int &i, unordered_map<int,int>&mp) {
        if(i>preorder.size() || l>r) return nullptr;
        int val = preorder[i++];
        int m = mp[val];
        TreeNode* root = new TreeNode(val);
        root->left = solve(preorder,l,m-1,i,mp);
        root->right = solve(preorder,m+1,r,i,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) {
            mp[inorder[i]]=i;
        }
        int start = 0;
        return solve(preorder,0,n-1,start,mp);
    }
};
