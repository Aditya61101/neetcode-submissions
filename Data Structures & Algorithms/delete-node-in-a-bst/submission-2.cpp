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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // if root->val == val, take its left and attach to leftmost of right
        // link its parent with root's right child, so if root was at the left of it's parent
        // it's right child would now be the left child of root's parent.
        if(!root) return nullptr;
        TreeNode* parent = nullptr, *curr=root;
        while(curr) {
            if(curr->val==key) {
                TreeNode* temp = curr;
                // if right node is not there
                if(!temp->right) {
                    if(!parent) { 
                        // delete curr; 
                        return temp->left; 
                    }
                    if(parent->val > temp->val) parent->left = temp->left;
                    else parent->right = temp->left;
                } else {
                    // the whole point of going to the leftmost of right subtree
                    // is to attach temp's left there, but if temp's left is not there
                    // then iterating doesn't makes sense.
                    if(temp->left) {
                        TreeNode* rightChild = temp->right;
                        while(rightChild->left) {
                            rightChild = rightChild->left;
                        }
                        rightChild->left = temp->left;
                    }
                    if(!parent) { 
                        // delete curr; 
                        return temp->right; 
                    }
                    if(parent->val > temp->val) parent->left = temp->right;
                    else parent->right = temp->right;
                }
                // delete curr;
                break;
            } else if(curr->val > key) {
                parent = curr;
                curr = curr->left;
            } else {
                parent = curr;
                curr = curr->right;
            }
        }
        return root;
    }
};