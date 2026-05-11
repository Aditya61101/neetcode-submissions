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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        stack<TreeNode*>st;
        while(curr || st.size()) {
            while(curr) {
                st.push(curr);
                // as soon as we are visting a node
                // we push it into our traversal array
                nodes.push_back(curr->val);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            curr=curr->right;
        }
        return nodes;
    }
};