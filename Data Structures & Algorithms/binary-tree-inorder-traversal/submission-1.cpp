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
    vector<int>nodes;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode* curr=root;
        while(curr || st.size()) {
            // traverse left
            while(curr) {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top(); st.pop();
            nodes.push_back(curr->val);
            curr=curr->right;
        }
        return nodes;
    }
};
// T.C: O(n), n=no. of nodes
// S.C: O(h), h=height of the tree