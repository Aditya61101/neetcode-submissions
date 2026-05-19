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
    bool check(TreeNode* r1, TreeNode*r2) {
        if(!r1 && !r2) return true;
        if(!r1 && r2 || r1 && !r2) return false;

        if(r1->val!=r2->val) return false;
        bool left = check(r1->left,r2->left);
        bool right = check(r1->right,r2->right);
        return left && right;
    }
    bool solve(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root && subRoot || root && !subRoot) return false;

        if(check(root,subRoot)) return true;
        bool left = solve(root->left,subRoot);
        bool right = solve(root->right,subRoot);
        return left || right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root,subRoot);
    }
};
