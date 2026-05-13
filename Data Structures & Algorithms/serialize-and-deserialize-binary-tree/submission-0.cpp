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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        if(!root) return str;
        
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()) {
            TreeNode* node = q.front(); q.pop();
            if(!node) {
                str+="#,"; continue;
            }
            str+=to_string(node->val)+',';
            q.push(node->left); q.push(node->right);
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        // data="1,2,#,#,3,"
        stringstream ss(data);
        string token;
        // token=1
        getline(ss,token,',');
        // token=2
        // getline(ss,token,',');
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            // constructing left child of node
            if(!getline(ss,token,',')) break;
            if(token!="#") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }
            // constructing right child of node
            if(!getline(ss,token,',')) break;
            if(token!="#") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }
        return root;
    }
};
