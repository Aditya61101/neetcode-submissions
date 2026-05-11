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
// postorder -> left,right,root | root,right,left
// preorder -> root,left,right
class Solution {
    vector<int>nodes;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        stack<TreeNode*>st;
        while(curr || st.size()) {
            while(curr) {
                nodes.push_back(curr->val);
                st.push(curr);
                curr=curr->right;
            }
            curr=st.top(); st.pop();
            curr=curr->left;
        }
        // nodes: root,right,left; after reverse, nodes: left,right,root
        reverse(nodes.begin(),nodes.end());
        return nodes;
    }
};